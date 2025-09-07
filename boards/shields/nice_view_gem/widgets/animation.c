#include <stdlib.h>
#include <zephyr/kernel.h>
#include "animation.h"

/* LV_IMG_DECLARE(crystal_01); */
/* LV_IMG_DECLARE(crystal_02); */
/* LV_IMG_DECLARE(crystal_03); */
/* LV_IMG_DECLARE(crystal_04); */
/* LV_IMG_DECLARE(crystal_05); */
/* LV_IMG_DECLARE(crystal_06); */
/* LV_IMG_DECLARE(crystal_07); */
/* LV_IMG_DECLARE(crystal_08); */
/* LV_IMG_DECLARE(crystal_09); */
/* LV_IMG_DECLARE(crystal_10); */
/* LV_IMG_DECLARE(crystal_11); */
/* LV_IMG_DECLARE(crystal_12); */
/* LV_IMG_DECLARE(crystal_13); */
/* LV_IMG_DECLARE(crystal_14); */
/* LV_IMG_DECLARE(crystal_15); */
/* LV_IMG_DECLARE(crystal_16); */

LV_IMG_DECLARE(emacs_new);
LV_IMG_DECLARE(emacs_old);
LV_IMG_DECLARE(org_mode);
LV_IMG_DECLARE(gnu);
LV_IMG_DECLARE(fedora);

const lv_img_dsc_t *anim_imgs[] = {
    &emacs_new, &emacs_old, &org_mode, &gnu, &fedora,
};

void draw_animation(lv_obj_t *canvas) {
#if IS_ENABLED(CONFIG_NICE_VIEW_GEM_ANIMATION)
    lv_obj_t *art = lv_animimg_create(canvas);
    lv_obj_center(art);

    lv_animimg_set_src(art, (const void **)anim_imgs, 5); // set this to the number of images
    /* lv_animimg_set_duration(art, CONFIG_NICE_VIEW_GEM_ANIMATION_MS); */
    lv_animimg_set_duration(art, 5000); // time (ms) of total duration
    lv_animimg_set_repeat_count(art, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(art);
#else
    lv_obj_t *art = lv_img_create(canvas);

    int length = sizeof(anim_imgs) / sizeof(anim_imgs[0]);
    srand(k_uptime_get_32());
    int random_index = rand() % length;

    lv_img_set_src(art, anim_imgs[random_index]);
#endif

    lv_obj_align(art, LV_ALIGN_TOP_LEFT, 36, 0);
}
