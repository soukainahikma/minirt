#include "minirt.h"

void sq_rotation(int key,t_move *move)
{
    double teta = 20 *M_PI/180;
    t_object *objec = malloc(sizeof(t_object));

    if(move->ptr->id == 7)
	{
    	objec->sq = move->ptr->obj;
		if(key == 125 || key == 126)
        {
		    if(key == 126)
			    teta = -1 * teta;
            objec->sq->sq_d = rot_x(objec->sq->sq_d,teta);
        }
		if(key == 123|| key == 124)
        {
			if(key == 124)
			    teta = -1 * teta;
            objec->sq->sq_d = rot_y(objec->sq->sq_d,teta);
            }
		if(key == 78 || key == 69)
        {
            if(key == 69)
			    teta = -1 * teta;
            objec->sq->sq_d = rot_z(objec->sq->sq_d,teta);
        }
        move->ptr->obj = objec->sq;
    }
}

void cylindre_rotation(int key,t_move *move)
{
    double teta = 20 * M_PI / 180;
    t_object *objec = malloc(sizeof(t_object));

    if(move->ptr->id == 8)
	{
    	objec->cy = move->ptr->obj;
		if(key == 125 || key == 126)
        {
		    if(key == 126)
			    teta = -1 * teta;
            objec->cy->cy_d = rot_x(objec->cy->cy_d,teta);
        }
		if(key == 123|| key == 124)
        {
			if(key == 124)
			    teta = -1 * teta;
            objec->cy->cy_d = rot_y(objec->cy->cy_d,teta);
        }
		if(key == 78 || key == 69)
        {
            if(key == 69)
			    teta = -1 * teta;
            objec->cy->cy_d = rot_z(objec->cy->cy_d,teta);
        }
        move->ptr->obj = objec->cy;
    }
}

void plan_rotation(int key,t_move *move)
{
    double teta = 20 *M_PI/180;
    t_object *objec = malloc(sizeof(t_object));

    if(move->ptr->id == 5)
	{
    	objec->plan = move->ptr->obj;
		if(key == 125 || key == 126)
        {
		    if(key == 126)
			    teta = -1 * teta;
            objec->plan->plan_d = rot_x(objec->plan->plan_d,teta);
        }
		if(key == 123|| key == 124)
        {
			if(key == 124)
			    teta = -1 * teta;
            objec->plan->plan_d = rot_y(objec->plan->plan_d,teta);
        }
		if(key == 78 || key == 69)
        {
            if(key == 69)
			    teta = -1 * teta;
            objec->plan->plan_d = rot_z(objec->plan->plan_d,teta);
        }
        move->ptr->obj = objec->plan;
    }
}