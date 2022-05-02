#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TouhouCharacterFigureWidget.h"
#include "../TorchModule/TorchModule.h"
class TouhouCharacterFigureWidget : public QMainWindow
{
	Q_OBJECT

public:
	TouhouCharacterFigureWidget(QWidget* parent = Q_NULLPTR);
private:
	Ui::TouhouCharacterFigureWidgetClass ui;
	TorchModule module;
};
