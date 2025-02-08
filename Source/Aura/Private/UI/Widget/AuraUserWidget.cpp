// Copyright Kaan Kirant


#include "UI/Widget/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetContoller(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
