#include "minirt.h"
void c_list_printer(t_cam_elm  *c_list)
{
    t_cam_elm *p;

    p = c_list;
    while (p != NULL)
    {
          t_camera *p5 = (t_camera *)p->cam;
                printf("camera ==(%.1lf,",p5->lookfrom.x);
                printf("%.1lf,",p5->lookfrom.y);
                printf("%.1lf)==",p5->lookfrom.z);
                printf("(%.1lf,", p5->cam_d.x) ;
                printf("%.1lf,", p5->cam_d.y) ;
                printf("%.1lf)==", p5->cam_d.z) ;
                printf("%.1lf==\n",p5->fov) ;
            p = p->next;
    }
}
void list_printer(t_element *list)
{
    t_element *p;

    p = list;
    while (p != NULL)
    {
        if(p->id == 4)
        {
            t_light *l = (t_light*)p->obj;
            printf("light ==(%.1f,", l->light_p.x);
            printf("%.1f,", l->light_p.y);
            printf("%.1f)==", l->light_p.z);
            printf("%.1f==", l->kl);
            printf("(%.1f,", l->color.x);
            printf(" %.1f,", l->color.y);
            printf("%.1f)\n", l->color.z);
        }
        if(p->id == 5)
        {
        t_plan *p1 = (t_plan *)p->obj;
        printf("plan ==(%.1f,", p1->plan_p.x);
        printf("%.1f,", p1->plan_p.y);
        printf("%.1f)==", p1->plan_p.z);
        printf("(%.1f,", p1->plan_d.x);
        printf("%.1f,", p1->plan_d.y);
        printf("%.1f)==", p1->plan_d.z);
        printf("(%.1f,", p1->plan_col.x);
        printf("%.1f,", p1->plan_col.y);
        printf("%.1f)\n", p1->plan_col.z);
       }
       if(p->id == 1)
       {
           t_resolution *p3 = (t_resolution *)p->obj;
       printf("resolution==(%.1lf,%.1lf)\n",p3->w,p3->h);
       }
        
       if(p->id == 2)
       {
        t_ambiant *p4 = (t_ambiant *)p->obj;
        printf("ambiant ==%.1lf==",p4->ka);
        printf("(%.1lf,",p4->amb_p.x);
        printf("%.1lf,",p4->amb_p.y);
        printf("%.1lf)==\n",p4->amb_p.z);
               }
        if(p->id == 3)
               {
                   t_camera *p5 = (t_camera *)p->obj;
                printf("camera ==(%.1lf,",p5->lookfrom.x);
                printf("%.1lf,",p5->lookfrom.y);
                printf("%.1lf)==",p5->lookfrom.z);
                printf("(%.1lf,", p5->cam_d.x) ;
                printf("%.1lf,", p5->cam_d.y) ;
                printf("%.1lf)==", p5->cam_d.z) ;
                printf("%.1lf==\n",p5->fov) ;
               }
        if(p->id == 6)
        {
        t_sphere *p6 = (t_sphere *)p->obj;
        printf("sphere ==(%.1f,", p6->sphere_p.x);
        printf("%.1f,", p6->sphere_p.y);
        printf("%.1f)==", p6->sphere_p.z);
        printf("%.1f==", p6->diametre);
        printf("(%.1f,", p6->sphere_col.x);
        printf("%.1f,", p6->sphere_col.y);
        printf("%.1f)\n", p6->sphere_col.z);
       }

       if(p->id == 7)
        {
        t_sq *p7 = (t_sq *)p->obj;
        printf("square ==(%.1f,", p7->sq_p.x);
        printf("%.1f,", p7->sq_p.y);
        printf("%.1f)==", p7->sq_p.z);
        printf("(%.1f,", p7->sq_d.x);
        printf("%.1f,", p7->sq_d.y);
        printf("%.1f)==", p7->sq_d.z);
        printf("%.1f==", p7->side_size);
        printf("(%.1f,", p7->sq_col.x);
        printf("%.1f,", p7->sq_col.y);
        printf("%.1f)\n", p7->sq_col.z);
       }
       if(p->id == 8)
        {
        t_cylindre *p8 = (t_cylindre *)p->obj;
        printf("cylindre ==(%.1f,", p8->cy_p.x);
        printf("%.1f,", p8->cy_p.y);
        printf("%.1f)==", p8->cy_p.z);
        printf("(%.1f,", p8->cy_d.x);
        printf("%.1f,", p8->cy_d.y);
        printf("%.1f)==", p8->cy_d.z);
        printf("%.1f==", p8->diam);
        printf("%.2f==", p8->h);
        printf("(%.1f,", p8->cy_col.x);
        printf("%.1f,", p8->cy_col.y);
        printf("%.1f)\n", p8->cy_col.z);
       }

        if(p->id == 9)
        {
        t_triangle *p9 = (t_triangle *)p->obj;
        printf("triangle ==(%.1f,", p9->tr_p1.x);
        printf("%.1f,", p9->tr_p1.y);
        printf("%.1f)==", p9->tr_p1.z);
        printf("(%.1f,", p9->tr_p2.x);
        printf("%.1f,", p9->tr_p2.y);
        printf("%.1f)==", p9->tr_p2.z);
        printf("(%.1f,", p9->tr_p3.x);
        printf("%.1f,", p9->tr_p3.y);
        printf("%.1f)==", p9->tr_p3.z);
        printf("(%.1f,", p9->tr_col.x);
        printf("%.1f,", p9->tr_col.y);
        printf("%.1f)\n", p9->tr_col.z);
       }

        p = p->next;


    }
    
}