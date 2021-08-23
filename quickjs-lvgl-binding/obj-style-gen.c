#include "lvgl.h"
#include "quickjs.h"
#include "quickjs-lvgl-binding.h"

STYLE_FUNC(width, INT, 0);
STYLE_FUNC(min_width, INT, 0);
STYLE_FUNC(max_width, INT, 0);
STYLE_FUNC(height, INT, 0);
STYLE_FUNC(min_height, INT, 0);
STYLE_FUNC(max_height, INT, 0);
STYLE_FUNC(x, INT, 0);
STYLE_FUNC(y, INT, 0);
STYLE_FUNC(align, INT, 0);
STYLE_FUNC(transform_width, INT, 0);
STYLE_FUNC(transform_height, INT, 0);
STYLE_FUNC(translate_x, INT, 0);
STYLE_FUNC(translate_y, INT, 0);
STYLE_FUNC(transform_zoom, INT, 0);
STYLE_FUNC(transform_angle, INT, 0);
STYLE_FUNC(pad_top, INT, 0);
STYLE_FUNC(pad_bottom, INT, 0);
STYLE_FUNC(pad_left, INT, 0);
STYLE_FUNC(pad_right, INT, 0);
STYLE_FUNC(pad_row, INT, 0);
STYLE_FUNC(pad_column, INT, 0);
STYLE_FUNC(radius, INT, 0);
STYLE_FUNC(clip_corner, INT, 0);
STYLE_FUNC(opa, INT, 0);
STYLE_FUNC(color_filter_opa, INT, 0);
STYLE_FUNC(anim_time, INT, 0);
STYLE_FUNC(anim_speed, INT, 0);
STYLE_FUNC(blend_mode, INT, 0);
STYLE_FUNC(layout, INT, 0);
STYLE_FUNC(base_dir, INT, 0);
STYLE_FUNC(bg_color, INT, 1);
STYLE_FUNC(bg_color_filtered, INT, 1);
STYLE_FUNC(bg_opa, INT, 0);
STYLE_FUNC(bg_grad_color, INT, 1);
STYLE_FUNC(bg_grad_color_filtered, INT, 1);
STYLE_FUNC(bg_grad_dir, INT, 0);
STYLE_FUNC(bg_main_stop, INT, 0);
STYLE_FUNC(bg_grad_stop, INT, 0);
STYLE_FUNC(bg_img_opa, INT, 0);
STYLE_FUNC(bg_img_recolor, INT, 1);
STYLE_FUNC(bg_img_recolor_filtered, INT, 1);
STYLE_FUNC(bg_img_recolor_opa, INT, 0);
STYLE_FUNC(bg_img_tiled, INT, 0);
STYLE_FUNC(border_color, INT, 1);
STYLE_FUNC(border_color_filtered, INT, 1);
STYLE_FUNC(border_opa, INT, 0);
STYLE_FUNC(border_width, INT, 0);
STYLE_FUNC(border_side, INT, 0);
STYLE_FUNC(border_post, INT, 0);
STYLE_FUNC(text_color, INT, 1);
STYLE_FUNC(text_color_filtered, INT, 1);
STYLE_FUNC(text_opa, INT, 0);
STYLE_FUNC(text_letter_space, INT, 0);
STYLE_FUNC(text_line_space, INT, 0);
STYLE_FUNC(text_decor, INT, 0);
STYLE_FUNC(text_align, INT, 0);
STYLE_FUNC(img_opa, INT, 0);
STYLE_FUNC(img_recolor, INT, 1);
STYLE_FUNC(img_recolor_filtered, INT, 1);
STYLE_FUNC(img_recolor_opa, INT, 0);
STYLE_FUNC(outline_width, INT, 0);
STYLE_FUNC(outline_color, INT, 1);
STYLE_FUNC(outline_color_filtered, INT, 1);
STYLE_FUNC(outline_opa, INT, 0);
STYLE_FUNC(outline_pad, INT, 0);
STYLE_FUNC(shadow_width, INT, 0);
STYLE_FUNC(shadow_ofs_x, INT, 0);
STYLE_FUNC(shadow_ofs_y, INT, 0);
STYLE_FUNC(shadow_spread, INT, 0);
STYLE_FUNC(shadow_color, INT, 1);
STYLE_FUNC(shadow_color_filtered, INT, 1);
STYLE_FUNC(shadow_opa, INT, 0);
STYLE_FUNC(line_width, INT, 0);
STYLE_FUNC(line_dash_width, INT, 0);
STYLE_FUNC(line_dash_gap, INT, 0);
STYLE_FUNC(line_rounded, INT, 0);
STYLE_FUNC(line_color, INT, 1);
STYLE_FUNC(line_color_filtered, INT, 1);
STYLE_FUNC(line_opa, INT, 0);
STYLE_FUNC(arc_width, INT, 0);
STYLE_FUNC(arc_rounded, INT, 0);
STYLE_FUNC(arc_color, INT, 1);
STYLE_FUNC(arc_color_filtered, INT, 1);
STYLE_FUNC(arc_opa, INT, 0);

static const JSCFunctionListEntry js_lvgl_obj_proto_funcs[] = {
  JS_CFUNC_DEF("setWidth", 1, js_lvgl_obj_set_width),
  JS_CFUNC_DEF("setMinWidth", 1, js_lvgl_obj_set_min_width),
  JS_CFUNC_DEF("setMaxWidth", 1, js_lvgl_obj_set_max_width),
  JS_CFUNC_DEF("setHeight", 1, js_lvgl_obj_set_height),
  JS_CFUNC_DEF("setMinHeight", 1, js_lvgl_obj_set_min_height),
  JS_CFUNC_DEF("setMaxHeight", 1, js_lvgl_obj_set_max_height),
  JS_CFUNC_DEF("setX", 1, js_lvgl_obj_set_x),
  JS_CFUNC_DEF("setY", 1, js_lvgl_obj_set_y),
  JS_CFUNC_DEF("setAlign", 1, js_lvgl_obj_set_align),
  JS_CFUNC_DEF("setTransformWidth", 1, js_lvgl_obj_set_transform_width),
  JS_CFUNC_DEF("setTransformHeight", 1, js_lvgl_obj_set_transform_height),
  JS_CFUNC_DEF("setTranslateX", 1, js_lvgl_obj_set_translate_x),
  JS_CFUNC_DEF("setTranslateY", 1, js_lvgl_obj_set_translate_y),
  JS_CFUNC_DEF("setTransformZoom", 1, js_lvgl_obj_set_transform_zoom),
  JS_CFUNC_DEF("setTransformAngle", 1, js_lvgl_obj_set_transform_angle),
  JS_CFUNC_DEF("setPadTop", 1, js_lvgl_obj_set_pad_top),
  JS_CFUNC_DEF("setPadBottom", 1, js_lvgl_obj_set_pad_bottom),
  JS_CFUNC_DEF("setPadLeft", 1, js_lvgl_obj_set_pad_left),
  JS_CFUNC_DEF("setPadRight", 1, js_lvgl_obj_set_pad_right),
  JS_CFUNC_DEF("setPadRow", 1, js_lvgl_obj_set_pad_row),
  JS_CFUNC_DEF("setPadColumn", 1, js_lvgl_obj_set_pad_column),
  JS_CFUNC_DEF("setRadius", 1, js_lvgl_obj_set_radius),
  JS_CFUNC_DEF("setClipCorner", 1, js_lvgl_obj_set_clip_corner),
  JS_CFUNC_DEF("setOpa", 1, js_lvgl_obj_set_opa),
  JS_CFUNC_DEF("setColorFilterOpa", 1, js_lvgl_obj_set_color_filter_opa),
  JS_CFUNC_DEF("setAnimTime", 1, js_lvgl_obj_set_anim_time),
  JS_CFUNC_DEF("setAnimSpeed", 1, js_lvgl_obj_set_anim_speed),
  JS_CFUNC_DEF("setBlendMode", 1, js_lvgl_obj_set_blend_mode),
  JS_CFUNC_DEF("setLayout", 1, js_lvgl_obj_set_layout),
  JS_CFUNC_DEF("setBaseDir", 1, js_lvgl_obj_set_base_dir),
  JS_CFUNC_DEF("setBgColor", 1, js_lvgl_obj_set_bg_color),
  JS_CFUNC_DEF("setBgColorFiltered", 1, js_lvgl_obj_set_bg_color_filtered),
  JS_CFUNC_DEF("setBgOpa", 1, js_lvgl_obj_set_bg_opa),
  JS_CFUNC_DEF("setBgGradColor", 1, js_lvgl_obj_set_bg_grad_color),
  JS_CFUNC_DEF("setBgGradColorFiltered", 1, js_lvgl_obj_set_bg_grad_color_filtered),
  JS_CFUNC_DEF("setBgGradDir", 1, js_lvgl_obj_set_bg_grad_dir),
  JS_CFUNC_DEF("setBgMainStop", 1, js_lvgl_obj_set_bg_main_stop),
  JS_CFUNC_DEF("setBgGradStop", 1, js_lvgl_obj_set_bg_grad_stop),
  JS_CFUNC_DEF("setBgImgOpa", 1, js_lvgl_obj_set_bg_img_opa),
  JS_CFUNC_DEF("setBgImgRecolor", 1, js_lvgl_obj_set_bg_img_recolor),
  JS_CFUNC_DEF("setBgImgRecolorFiltered", 1, js_lvgl_obj_set_bg_img_recolor_filtered),
  JS_CFUNC_DEF("setBgImgRecolorOpa", 1, js_lvgl_obj_set_bg_img_recolor_opa),
  JS_CFUNC_DEF("setBgImgTiled", 1, js_lvgl_obj_set_bg_img_tiled),
  JS_CFUNC_DEF("setBorderColor", 1, js_lvgl_obj_set_border_color),
  JS_CFUNC_DEF("setBorderColorFiltered", 1, js_lvgl_obj_set_border_color_filtered),
  JS_CFUNC_DEF("setBorderOpa", 1, js_lvgl_obj_set_border_opa),
  JS_CFUNC_DEF("setBorderWidth", 1, js_lvgl_obj_set_border_width),
  JS_CFUNC_DEF("setBorderSide", 1, js_lvgl_obj_set_border_side),
  JS_CFUNC_DEF("setBorderPost", 1, js_lvgl_obj_set_border_post),
  JS_CFUNC_DEF("setTextColor", 1, js_lvgl_obj_set_text_color),
  JS_CFUNC_DEF("setTextColorFiltered", 1, js_lvgl_obj_set_text_color_filtered),
  JS_CFUNC_DEF("setTextOpa", 1, js_lvgl_obj_set_text_opa),
  JS_CFUNC_DEF("setTextLetterSpace", 1, js_lvgl_obj_set_text_letter_space),
  JS_CFUNC_DEF("setTextLineSpace", 1, js_lvgl_obj_set_text_line_space),
  JS_CFUNC_DEF("setTextDecor", 1, js_lvgl_obj_set_text_decor),
  JS_CFUNC_DEF("setTextAlign", 1, js_lvgl_obj_set_text_align),
  JS_CFUNC_DEF("setImgOpa", 1, js_lvgl_obj_set_img_opa),
  JS_CFUNC_DEF("setImgRecolor", 1, js_lvgl_obj_set_img_recolor),
  JS_CFUNC_DEF("setImgRecolorFiltered", 1, js_lvgl_obj_set_img_recolor_filtered),
  JS_CFUNC_DEF("setImgRecolorOpa", 1, js_lvgl_obj_set_img_recolor_opa),
  JS_CFUNC_DEF("setOutlineWidth", 1, js_lvgl_obj_set_outline_width),
  JS_CFUNC_DEF("setOutlineColor", 1, js_lvgl_obj_set_outline_color),
  JS_CFUNC_DEF("setOutlineColorFiltered", 1, js_lvgl_obj_set_outline_color_filtered),
  JS_CFUNC_DEF("setOutlineOpa", 1, js_lvgl_obj_set_outline_opa),
  JS_CFUNC_DEF("setOutlinePad", 1, js_lvgl_obj_set_outline_pad),
  JS_CFUNC_DEF("setShadowWidth", 1, js_lvgl_obj_set_shadow_width),
  JS_CFUNC_DEF("setShadowOfsX", 1, js_lvgl_obj_set_shadow_ofs_x),
  JS_CFUNC_DEF("setShadowOfsY", 1, js_lvgl_obj_set_shadow_ofs_y),
  JS_CFUNC_DEF("setShadowSpread", 1, js_lvgl_obj_set_shadow_spread),
  JS_CFUNC_DEF("setShadowColor", 1, js_lvgl_obj_set_shadow_color),
  JS_CFUNC_DEF("setShadowColorFiltered", 1, js_lvgl_obj_set_shadow_color_filtered),
  JS_CFUNC_DEF("setShadowOpa", 1, js_lvgl_obj_set_shadow_opa),
  JS_CFUNC_DEF("setLineWidth", 1, js_lvgl_obj_set_line_width),
  JS_CFUNC_DEF("setLineDashWidth", 1, js_lvgl_obj_set_line_dash_width),
  JS_CFUNC_DEF("setLineDashGap", 1, js_lvgl_obj_set_line_dash_gap),
  JS_CFUNC_DEF("setLineRounded", 1, js_lvgl_obj_set_line_rounded),
  JS_CFUNC_DEF("setLineColor", 1, js_lvgl_obj_set_line_color),
  JS_CFUNC_DEF("setLineColorFiltered", 1, js_lvgl_obj_set_line_color_filtered),
  JS_CFUNC_DEF("setLineOpa", 1, js_lvgl_obj_set_line_opa),
  JS_CFUNC_DEF("setArcWidth", 1, js_lvgl_obj_set_arc_width),
  JS_CFUNC_DEF("setArcRounded", 1, js_lvgl_obj_set_arc_rounded),
  JS_CFUNC_DEF("setArcColor", 1, js_lvgl_obj_set_arc_color),
  JS_CFUNC_DEF("setArcColorFiltered", 1, js_lvgl_obj_set_arc_color_filtered),
  JS_CFUNC_DEF("setArcOpa", 1, js_lvgl_obj_set_arc_opa),
};