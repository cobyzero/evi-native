#include "include/core/SkCanvas.h"
#include "include/core/SkSurface.h"
#include "include/core/SkGraphics.h"
#include "skia_renderer.h"
#include "ts_runtime.h"
#include "quickjs/quickjs.h"

void native_main_loop() {
    SkGraphics::Init();

    auto surface = SkSurface::MakeRasterN32Premul(640, 480);
    SkCanvas* canvas = surface->getCanvas();
    init_renderer(canvas);

    JSRuntime* rt = JS_NewRuntime();
    JSContext* ctx = JS_NewContext(rt);
    run_ts(ctx);

    surface->flushAndSubmit();
    // Integrar con Android: mostrar surface usando EGL o ANativeWindow
}