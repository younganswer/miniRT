#include "../../libs/libmlx/incs/mlx.h"
#include "../../incs/render.h"
#include "../../incs/raytracing.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
const size_t	g_samples = 9;
double get_plane_color(t_plane *p);

t_ray *primary__ray(t_var *var, double i, double j)
{
    t_ray *ray;
    ray = malloc(sizeof(t_ray));
    ray->origin = var->camera->ray.origin;
    t_vec3 temp;
    t_vec3 temp2;
    temp = vec3_mul(var->camera->horizontal, (j / (SCREEN_WIDTH - 1)));
    temp2 = vec3_mul(var->camera->vertical, (i / (SCREEN_HEIGHT - 1)));
    ray->direction = vec3_sub(temp, temp2);
    ray->direction = vec3_add(ray->direction, var->camera->higher_left_corner);
    ray->direction = vec3_sub(ray->direction, ray->origin);
    ray->direction = vec3_unit(ray->direction);
    return (ray);
}

t_hit *hit_plane(t_var *var, t_plane *plane, t_ray *ray)
{
    double t;
    t = 0;
    double p_dot;
    double tmp;
    t_vec3 vec_tmp;
    t_hit *hit = malloc(sizeof(t_hit));
    p_dot = vec3_dot(plane->normal, ray->direction);
    tmp = vec3_dot(vec3_sub(plane->point, ray->origin), plane->normal);
    hit->d = tmp / p_dot;
    if (hit->d <= 0)
        return (NULL);
    hit->ray.direction = vec3_mul(ray->direction, hit->d);
    hit->ray = *ray;
    hit->normal = plane->normal;
    hit->normal = vec3_unit(hit->normal);
    hit->color = get_plane_color(plane);
    return (hit);

}

double check_hit(t_var *var, t_object *obj, t_ray *ray)
{
    t_hit *hit;
    if (obj->shape == 1)
    {
        hit = hit_plane(var, obj->object, ray);
        if (!hit)
            return (INF);
    }
    //else if(obj->shape == 0)
    //    ret = hit_sphere(var, obj->object, ray);
    else
        hit->d = INF;
    return (hit->d);
}

t_hit *get_near_one(t_var *var, t_ray *ray, t_object *hit_obj)
{
    double min_d;
    double temp_d;
    min_d = INF;
    t_list *o;
    t_object *obj;
    t_hit *hit;

    o = var->objects;
    while (o)
    {
        obj = o->content;
        t_plane *p= obj->object;

        temp_d = check_hit(var, obj, ray);
        if (temp_d <= min_d)
        {
            min_d = temp_d;
            if (obj->shape == 1)//plane인경우
            {
                hit = hit_plane(var, obj->object, ray);
            }
        }
        o = o->next;
    }

    return (hit);
}

double hell(t_vec3 *h_normal, t_vec3 *light, t_ray *ray)
{
    double t1;
    double t2;
    t1 = vec3_dot(*h_normal, *light);
    t2 = vec3_dot(*h_normal, ray->direction);
    if (t1 < 0)
    {
        h_normal->x = -(h_normal->x);
        h_normal->y = -(h_normal->y);
        h_normal->z = -(h_normal->z);
    }
    if (t1 < 0 && t2 < 0)
        return (1);
    if (t1 >= 0 && t2 >= 0)
        return (1);
    return (0);
}

double angle(t_vec3 light, t_vec3 h_normal)
{
    double scalar;
    scalar = vec3_dot(light, h_normal);
    return (acos(scalar));


}
double get_light(t_var *var, t_ray *ray, t_object *hit_obj, double d)
{
    t_vec3 h_normal;
    t_vec3 light;
    t_vec3 impact;
    t_vec3 light_dir;
    double bright;
    t_light *l = var->lights->content;
    impact = (t_vec3){0, 0, 1};
    light = vec3_unit(vec3_sub(impact, l->origin));
    if (hit_obj->shape == 1) //plane일때
    {
        t_plane *p = hit_obj->object;
        h_normal = p->normal;
    }
    if (hit_obj->shape == 1 && hell(&h_normal, &light, ray))
        return (0);
    bright = 1 - (2 * fabs(angle(vec3_unit(light), vec3_unit(h_normal))) / 3.14);
    return (bright);
}

double get_plane_color(t_plane *p)
{
    return((unsigned int)(p->color.x) << 16 | (unsigned int)(p->color.y) << 8 | (unsigned int)(p->color.z));
}


unsigned int get_pixel(t_var *var, int i, int j)
{
    t_vec3 color;
    t_ray *ray;
    t_object *hit_obj;
    t_light *light_tmp = var->lights->content;
    t_hit *hit;
    hit_obj = malloc(sizeof(t_object));

    double d;
    double light;
    double l;
    ray = primary__ray(var, i, j);
    //printf("ray %f %f %f\n",ray->direction.x, ray->direction.y, ray->direction.z);
    color = (t_vec3){0, 0, 0};
    hit = get_near_one(var, ray, hit_obj);
    //printf("hit->obj %f %f %f %f\n", hit->d, hit->normal.x, hit->normal.y, hit->normal.z);
    //printf("hit normal %f %f %f\n",hit->normal.x, hit->normal.y, hit->normal.z);
    if (!hit_obj)
        return (0);
    light = get_light(var, ray, hit_obj, hit->d);
    l = var->alight->ratio + light_tmp->ratio;
    //if (hit_obj->shape == 1)
    //    return (get_plane_color(hit_obj->object));
    return (hit->color);
}

unsigned int get_color(t_var *var)
{
    t_list *obj = var->objects;
    t_object *object = var->objects->content;
    t_plane *p = object->object;
    return ((unsigned int)(p->color.x) << 16 | (unsigned int)(p->color.y) << 8 | (unsigned int)(p->color.z));
    return 0;
}

int				render(t_var *var)
{
    int i = 0;
    int j = 0;
    while (i < SCREEN_HEIGHT)
    {
        j = 0;
        while (j < SCREEN_WIDTH)
        {
            var->img->addr[i * SCREEN_WIDTH + j] = get_pixel(var, i, j);
            j++;
        }
        i++;
    }
	mlx_put_image_to_window(var->mlx->mlx, var->mlx->window, var->img->img, 0, 0);
	return (TRUE);
}


