#include "quickjs/quickjs.h"
#include "skia_renderer.h"

JSValue js_drawRect(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
    double x, y, w, h;
    JS_ToFloat64(ctx, &x, argv[0]);
    JS_ToFloat64(ctx, &y, argv[1]);
    JS_ToFloat64(ctx, &w, argv[2]);
    JS_ToFloat64(ctx, &h, argv[3]);
    draw_rect(x, y, w, h);
    return JS_UNDEFINED;
}

void run_ts(JSContext* ctx) {
    JSValue global = JS_GetGlobalObject(ctx);
    JS_SetPropertyStr(ctx, global, "drawRect", JS_NewCFunction(ctx, js_drawRect, "drawRect", 4));

    const char* code = "drawRect(100, 100, 150, 150);";
    JS_Eval(ctx, code, strlen(code), "<input>", JS_EVAL_TYPE_GLOBAL);
}