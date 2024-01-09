#include "Window/HorizontalLayout.h"

#include "Window/Container.h"
#include "Window/Context.h"

namespace PPEngine {
    namespace Window {
        HorizontalLayout::HorizontalLayout() : Container() {}

        HorizontalLayout::~HorizontalLayout() {}

        Control::Ptr HorizontalLayout::Create() {
            return std::make_shared<HorizontalLayout>();
        }

        void HorizontalLayout::SetAttribute(const char* name, const char* value) {
            if (0 == strcmp(name, "sepheight")) {
                SetSepWidth(atoi(value));
            } else if (0 == strcmp(name, "sepimm")) {
                SetSepImmMode(strcmp(value, "true") == 0);
            } else {
                Container::SetAttribute(name, value);
            }
        }

        void HorizontalLayout::SetRect(const Core::Math::Rect& rect) {
            Container::SetRect(rect);

            Core::Math::Rect rc(rect_);
        }

        void HorizontalLayout::OnDraw(const Core::Math::Rect& rect) {
        }

        void HorizontalLayout::SetSepImmMode(bool immediately) {
            if (immediately_ == immediately) return;
            if (captured_ && !immediately_ && nullptr != GetContext()) {
                GetContext()->RemovePostPaint(this);
            }

            immediately_ = immediately;
        }

    }
}
