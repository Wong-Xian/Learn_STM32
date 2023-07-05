#include "my_gui.h"
#include "lvgl.h"

void my_gui(void)
{
    BasicObject();
}

void L_arc(void)
{
    /*** arc1 ***/
    lv_obj_t* arc1 = lv_arc_create(lv_scr_act());    // 创建arc对象
    lv_obj_set_size(arc1, 100, 100);                 // 设置arc大小

    lv_arc_set_rotation(arc1, 0);                    // 设置arc旋转角度
    lv_arc_set_bg_angles(arc1, 0,180);               // 设置arc的范围
    lv_arc_set_value(arc1, 50);                      // 设置arc当前的值 百分数

//    lv_obj_center(arc1);                             // 把arc放置在屏幕中间
//    lv_obj_set_align(arc1, LV_ALIGN_CENTER);         // 中间对齐
    lv_obj_set_pos(arc1, 10, 10);


    /*** arc2 ***/
    lv_obj_t* arc2 = lv_arc_create(lv_scr_act());    // 创建arc对象
    lv_obj_set_size(arc2, 100, 100);                 // 设置arc大小

    lv_arc_set_rotation(arc2, 90);                    // 设置arc旋转角度
    lv_arc_set_bg_angles(arc2, 0,180);               // 设置arc的范围
    lv_arc_set_value(arc2, 50);                      // 设置arc当前的值 百分数

    lv_obj_set_pos(arc2, 120, 10);


    /*** arc3 ***/
    lv_obj_t* arc3 = lv_arc_create(lv_scr_act());    // 创建arc对象
    lv_obj_set_size(arc3, 100, 100);                 // 设置arc大小

    lv_arc_set_rotation(arc3, 180);                    // 设置arc旋转角度
    lv_arc_set_bg_angles(arc3, 0,180);               // 设置arc的范围
    lv_arc_set_value(arc3, 50);                      // 设置arc当前的值 百分数

    lv_obj_set_pos(arc3, 230, 10);


    /*** arc4 ***/
    lv_obj_t* arc4 = lv_arc_create(lv_scr_act());
    lv_obj_set_size(arc4, 100, 100);

    lv_arc_set_rotation(arc4, 170);
    lv_arc_set_bg_angles(arc4, 0, 200);
    lv_arc_set_value(arc4, 50);

    lv_obj_set_pos(arc4, 340, 10);

    /*** arc5 ***/
    lv_obj_t* arc5 = lv_arc_create(lv_scr_act());
    lv_obj_set_size(arc5, 100, 100);

    lv_arc_set_rotation(arc5, 160);
    lv_arc_set_bg_angles(arc5, 0, 220);
    lv_arc_set_value(arc5, 50);

    lv_obj_set_pos(arc5, 450, 10);


    /*** arc6 ***/
    lv_obj_t* arc6 = lv_arc_create(lv_scr_act());
    lv_obj_set_size(arc6, 100, 100);

    lv_arc_set_rotation(arc6, 150);
    lv_arc_set_bg_angles(arc6, 0, 240);
    lv_arc_set_value(arc6, 50);

    lv_arc_set_mode(arc6, LV_ARC_MODE_REVERSE);// 滑块在中间，可向两边滑动
    lv_obj_set_pos(arc6, 560, 10);


    /*** arc7 ***/
    lv_obj_t* arc7 = lv_arc_create(lv_scr_act());
    lv_obj_set_size(arc7, 100, 100);

    lv_arc_set_rotation(arc7, 140);
    lv_arc_set_bg_angles(arc7, 0, 260);
    lv_arc_set_value(arc7, 50);

    lv_arc_set_mode(arc7, LV_ARC_MODE_SYMMETRICAL);// 滑块在最右边，可往左滑动
    lv_obj_set_pos(arc7, 670, 10);


    /*** arc8 unclickable ***/
    lv_obj_t* arc8 = lv_arc_create(lv_scr_act());
    lv_obj_set_size(arc8, 100, 100);

    lv_arc_set_rotation(arc8, 140);
    lv_arc_set_bg_angles(arc8, 0, 260);
    lv_arc_set_value(arc8, 40);

    lv_obj_set_pos(arc8, 10, 120);

    lv_obj_remove_style(arc8, NULL, LV_PART_KNOB);
    lv_obj_clear_flag(arc8, LV_OBJ_FLAG_CLICKABLE);
}


/* 基础对象的使用 */
void BasicObject(void)
{
    lv_obj_t* obj1 = lv_obj_create(lv_scr_act());   // 创建基础对象
    /* 运行结果，基础部件就是一个矩形框 */

    lv_obj_set_size(obj1, 700, 400);    // 调整基础对象的大小

    lv_obj_t* switch1 = lv_switch_create(obj1); // 以obj1为父对象，创建一个开关
    lv_obj_set_size(switch1, 120, 60);      // 设置开关大小
    lv_obj_set_pos(switch1, 100, 100);      // 设置开关位置

    lv_obj_set_pos(obj1, 20, 20);       // 调整父对象的位置
}
