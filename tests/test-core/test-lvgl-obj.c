#include "jerryscript.h"
#include "lvgl.h"
#include "../bi-test-assert.h"
#include "lvgl-common.h"
#include "jerry-lvgl-binding.h"

void test_append_child() {
    BI_TEST_START;
    jerry_init(JERRY_INIT_EMPTY);

    js_lvgl_obj_init();

    const char code[] = "let a = new LvglObj(); let b = new LvglObj(); let c = new LvglObj(); a.appendChild(c); a.appendChild(b); [a, b];";
    jerry_value_t ret = jerry_eval((const jerry_char_t *) code, sizeof(code) - 1, JERRY_PARSE_NO_OPTS);

    char *str = NULL;
    BI_ASSERT_TRUE(!jerry_value_is_error(ret), str = jerry_to_c_string(jerry_get_value_from_error(ret, true)));
    jerry_free_c_string(str);

    BI_ASSERT_TRUE(jerry_value_is_array(ret), "eval result is not array!");

    jerry_value_t a = jerry_get_property_by_index(ret, 0);
    jerry_value_t b = jerry_get_property_by_index(ret, 1);
    lv_obj_t *a_obj = NULL;
    lv_obj_t *b_obj = NULL;
    if (js_lvgl_get_native_info(a, (void **) &a_obj) && js_lvgl_get_native_info(b, (void **) &b_obj)) {
        uint32_t index = lv_obj_get_child_id(b_obj);
        BI_ASSERT_TRUE(index == 1, "");
        BI_ASSERT_TRUE(b_obj->parent == a_obj, "");
    } else {
        BI_ASSERT_TRUE(false, "cannot get lvgl obj from js object!");
    }


    jerry_release_value(a);
    jerry_release_value(b);
    jerry_release_value(ret);

    jerry_cleanup();
    BI_TEST_END;
}

void test_remove_child() {
    BI_TEST_START;
    jerry_init(JERRY_INIT_EMPTY);
    
    js_lvgl_obj_init();

    const char code[] = "let a = new LvglObj(); let b = new LvglObj(); a.appendChild(b); a.removeChild(b); [a, b];";
    jerry_value_t ret = jerry_eval((const jerry_char_t *) code, sizeof(code) - 1, JERRY_PARSE_NO_OPTS);
    BI_ASSERT_TRUE(jerry_value_is_array(ret), "eval result is not array!");

    jerry_value_t a = jerry_get_property_by_index(ret, 0);
    jerry_value_t b = jerry_get_property_by_index(ret, 1);
    lv_obj_t *a_obj = NULL;
    lv_obj_t *b_obj = NULL;
    if (js_lvgl_get_native_info(a, (void **) &a_obj) && js_lvgl_get_native_info(b, (void **) &b_obj)) {
        uint32_t cnt = lv_obj_get_child_cnt(a_obj);
        BI_ASSERT_TRUE(cnt == 0, "");
        BI_ASSERT_TRUE(b_obj->parent == js_lvgl_get_detach_screen(), "");
    } else {
        BI_ASSERT_TRUE(false, "cannot get lvgl obj from js object!");
    }

    jerry_release_value(a);
    jerry_release_value(b);
    jerry_release_value(ret);

    jerry_cleanup();
    BI_TEST_END;
}

void test_insert_before_without_append() {
    BI_TEST_START;

    jerry_init(JERRY_INIT_EMPTY);
    
    js_lvgl_obj_init();

    const char code[] = "let a = new LvglObj(); let b = new LvglObj(); let c = new LvglObj(); a.appendChild(b); a.insertBefore(c, b); [a, b, c];";
    jerry_value_t ret = jerry_eval((const jerry_char_t *) code, sizeof(code) - 1, JERRY_PARSE_NO_OPTS);
    BI_ASSERT_TRUE(jerry_value_is_array(ret), "eval result is not array!");

    jerry_value_t a = jerry_get_property_by_index(ret, 0);
    jerry_value_t b = jerry_get_property_by_index(ret, 1);
    jerry_value_t c = jerry_get_property_by_index(ret, 2);
    lv_obj_t *a_obj = NULL;
    lv_obj_t *b_obj = NULL;
    lv_obj_t *c_obj = NULL;
    if (js_lvgl_get_native_info(a, (void **) &a_obj) 
        && js_lvgl_get_native_info(b, (void **) &b_obj)
        && js_lvgl_get_native_info(c, (void **) &c_obj)
    ) {
        uint32_t cnt = lv_obj_get_child_cnt(a_obj);
        BI_ASSERT_TRUE(cnt == 2, "");
        lv_obj_t **children = a_obj->spec_attr->children;
        uint32_t id = lv_obj_get_child_id(b_obj);
        BI_ASSERT_TRUE(children[0] == c_obj, "");
        BI_ASSERT_TRUE(children[1] == b_obj, "");
    } else {
        BI_ASSERT_TRUE(false, "cannot get lvgl obj from js object!");
    }

    jerry_release_value(a);
    jerry_release_value(b);
    jerry_release_value(c);
    jerry_release_value(ret);

    jerry_cleanup();
    BI_TEST_END;
}

void test_insert_before_with_append() {
    BI_TEST_START;

    jerry_init(JERRY_INIT_EMPTY);
    
    js_lvgl_obj_init();

    const char code[] = "let a = new LvglObj(); let b = new LvglObj(); let c = new LvglObj(); a.appendChild(b); a.appendChild(c); a.insertBefore(c, b); [a, b, c];";
    jerry_value_t ret = jerry_eval((const jerry_char_t *) code, sizeof(code) - 1, JERRY_PARSE_NO_OPTS);
    BI_ASSERT_TRUE(jerry_value_is_array(ret), "eval result is not array!");

    jerry_value_t a = jerry_get_property_by_index(ret, 0);
    jerry_value_t b = jerry_get_property_by_index(ret, 1);
    jerry_value_t c = jerry_get_property_by_index(ret, 2);
    lv_obj_t *a_obj = NULL;
    lv_obj_t *b_obj = NULL;
    lv_obj_t *c_obj = NULL;
    if (js_lvgl_get_native_info(a, (void **) &a_obj) 
        && js_lvgl_get_native_info(b, (void **) &b_obj)
        && js_lvgl_get_native_info(c, (void **) &c_obj)
    ) {
        uint32_t cnt = lv_obj_get_child_cnt(a_obj);
        BI_ASSERT_TRUE(cnt == 2, "");
        lv_obj_t **children = a_obj->spec_attr->children;
        uint32_t id = lv_obj_get_child_id(b_obj);
        BI_ASSERT_TRUE(children[0] == c_obj, "");
        BI_ASSERT_TRUE(children[1] == b_obj, "");
    } else {
        BI_ASSERT_TRUE(false, "cannot get lvgl obj from js object!");
    }

    jerry_release_value(a);
    jerry_release_value(b);
    jerry_release_value(c);
    jerry_release_value(ret);

    jerry_cleanup();
    BI_TEST_END;
}