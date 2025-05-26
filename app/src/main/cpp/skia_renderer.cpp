#include "include/skia_renderer.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkPaint.h"
#include "include/core/SkSurface.h"

SkCanvas* canvas = nullptr;

void init_renderer(SkCanvas* c) {
    canvas = c;
}

void draw_rect(float x, float y, float w, float h) {
    if (!canvas) return;

    SkPaint paint;
    paint.setColor(SK_ColorBLUE);
    canvas->drawRect(SkRect::MakeXYWH(x, y, w, h), paint);
}