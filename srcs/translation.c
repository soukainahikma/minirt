#include "minirt.h"

void sphere_translation(int key,t_move *move)
{
    t_object *objec = malloc(sizeof(t_object));
            if(move->ptr->id == 6)
			{
    			objec->sphere = move->ptr->obj;
				if(key == 123)	
    				objec->sphere->sphere_p.x = objec->sphere->sphere_p.x - 5;
				if(key == 124)	
    				objec->sphere->sphere_p.x = objec->sphere->sphere_p.x + 5;
				if(key == 126)
    				objec->sphere->sphere_p.y = objec->sphere->sphere_p.y + 5;
				if(key == 125)	
    				objec->sphere->sphere_p.y = objec->sphere->sphere_p.y - 5;
				if(key == 78)
    				objec->sphere->sphere_p.z = objec->sphere->sphere_p.z - 5;
				if(key == 69)	
    				objec->sphere->sphere_p.z = objec->sphere->sphere_p.z + 5;
				
				move->ptr->obj = objec->sphere ;
			}
}
void sq_translation(int key,t_move *move)
{
    t_object *objec = malloc(sizeof(t_object));
            if(move->ptr->id == 7)
			{
    			objec->sq = move->ptr->obj;
				if(key == 123)	
    				objec->sq->sq_p.x = objec->sq->sq_p.x - 5;
				if(key == 124)	
    				objec->sq->sq_p.x = objec->sq->sq_p.x + 5;
				if(key == 126)
    				objec->sq->sq_p.y = objec->sq->sq_p.y + 5;
				if(key == 125)	
    				objec->sq->sq_p.y = objec->sq->sq_p.y - 5;
				if(key == 78)
    				objec->sq->sq_p.z = objec->sq->sq_p.z - 5;
				if(key == 69)	
    				objec->sq->sq_p.z = objec->sq->sq_p.z + 5;
				
				move->ptr->obj = objec->sq ;
			}
}
void cylindre_translation(int key,t_move *move)
{
    t_object *objec = malloc(sizeof(t_object));
            if(move->ptr->id == 8)
			{
    			objec->cy = move->ptr->obj;
				if(key == 123)	
    				objec->cy->cy_p.x =objec->cy->cy_p.x-5;
				if(key == 124)	
    				objec->cy->cy_p.x =objec->cy->cy_p.x+5;
				if(key == 126)
    				objec->cy->cy_p.y =objec->cy->cy_p.y+5;
				if(key == 125)	
    				objec->cy->cy_p.y =objec->cy->cy_p.y-5;
				if(key == 78)
    				objec->cy->cy_p.z =objec->cy->cy_p.z-5;
				if(key == 69)	
    				objec->cy->cy_p.z =objec->cy->cy_p.z+5;
				
				move->ptr->obj = objec->cy ;
			}
}

void plan_translation(int key,t_move *move)
{
    t_object *objec = malloc(sizeof(t_object));
            if(move->ptr->id == 5)
			{
    			objec->plan = move->ptr->obj;
				if(key == 123)	
    				objec->plan->plan_p.x=objec->plan->plan_p.x-5;
				if(key == 124)	
    				objec->plan->plan_p.x=objec->plan->plan_p.x+5;
				if(key == 126)
    				objec->plan->plan_p.y=objec->plan->plan_p.y+5;
				if(key == 125)	
    				objec->plan->plan_p.y=objec->plan->plan_p.y-5;
				if(key == 78)
    				objec->plan->plan_p.z=objec->plan->plan_p.z-5;
				if(key == 69)	
    				objec->plan->plan_p.z=objec->plan->plan_p.z+5;
				move->ptr->obj = objec->plan ;
			}
}
void triangle_translation(int key,t_move *move)
{
    t_object *objec = malloc(sizeof(t_object));
            if(move->ptr->id == 9)
			{
    			objec->triangle = move->ptr->obj;
				if(key == 123)
				{
    				objec->triangle->tr_p1.x= objec->triangle->tr_p1.x-5;
    				objec->triangle->tr_p2.x= objec->triangle->tr_p2.x-5;
    				objec->triangle->tr_p3.x= objec->triangle->tr_p3.x-5;
				}
				if(key == 124)	
				{
					objec->triangle->tr_p1.x= objec->triangle->tr_p1.x+5;
					objec->triangle->tr_p2.x= objec->triangle->tr_p2.x+5;
					objec->triangle->tr_p3.x= objec->triangle->tr_p3.x+5;
				}
				if(key == 126)
				{
					objec->triangle->tr_p1.y= objec->triangle->tr_p1.y+5;
					objec->triangle->tr_p2.y= objec->triangle->tr_p2.y+5;
					objec->triangle->tr_p3.y= objec->triangle->tr_p3.y+5;
				}
				if(key == 125)	
    				{
					objec->triangle->tr_p1.y= objec->triangle->tr_p1.y-5;
					objec->triangle->tr_p2.y= objec->triangle->tr_p2.y-5;
					objec->triangle->tr_p3.y= objec->triangle->tr_p3.y-5;
				}
				if(key == 78)
    				{
					objec->triangle->tr_p1.z= objec->triangle->tr_p1.z-5;
					objec->triangle->tr_p2.z= objec->triangle->tr_p2.z-5;
					objec->triangle->tr_p3.z= objec->triangle->tr_p3.z-5;
				}
				if(key == 69)	
    				{
					objec->triangle->tr_p1.z= objec->triangle->tr_p1.z+5;
					objec->triangle->tr_p2.z= objec->triangle->tr_p2.z+5;
					objec->triangle->tr_p3.z= objec->triangle->tr_p3.z+5;
				}
				
				move->ptr->obj = objec->triangle ;
			}
}
