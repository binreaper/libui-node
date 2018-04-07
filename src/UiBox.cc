#include "nbind/api.h"
#include "box.h"
#include "control.h"
#include "ui.h"

class UiBox : public UiControl {
  public:
	UiBox(uiControl *hnd);
	DEFINE_BOX_METHODS()
};

class UiVerticalBox : public UiBox {
  public:
	UiVerticalBox();
	DEFINE_BOX_METHODS()
	DEFINE_CONTROL_METHODS()
};

class UiHorizontalBox : public UiBox {
  public:
	UiHorizontalBox();
	DEFINE_BOX_METHODS()
	DEFINE_CONTROL_METHODS()
};

UiBox::UiBox(uiControl *control) : UiControl(control) {}

void UiBox::append(UiControl *control, bool stretchy) {
	uiBoxAppend((uiBox *)getHandle(), control->getHandle(), stretchy);
}

void UiBox::deleteAt(int index) {
	uiBoxDelete((uiBox *)getHandle(), index);
}

void UiBox::setPadded(bool padded) {
	uiBoxSetPadded((uiBox *)getHandle(), padded);
}

bool UiBox::getPadded() {
	return uiBoxPadded((uiBox *)getHandle());
}

UiVerticalBox::UiVerticalBox() : UiBox((uiControl *)uiNewVerticalBox()) {}

INHERITS_CONTROL_METHODS(UiVerticalBox)
INHERITS_BOX_METHODS(UiVerticalBox)

UiHorizontalBox::UiHorizontalBox() : UiBox((uiControl *)uiNewHorizontalBox()) {}

INHERITS_CONTROL_METHODS(UiHorizontalBox)
INHERITS_BOX_METHODS(UiHorizontalBox)

NBIND_CLASS(UiVerticalBox) {
	construct<>();
	DECLARE_CHILD_CONTROL_METHODS()
	DECLARE_BOX_METHODS()
}

NBIND_CLASS(UiHorizontalBox) {
	construct<>();
	DECLARE_CHILD_CONTROL_METHODS()
	DECLARE_BOX_METHODS()
}
