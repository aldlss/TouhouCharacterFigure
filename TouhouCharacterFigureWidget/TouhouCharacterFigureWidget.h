﻿#ifndef _TCFW_
#define _TCFW_

#ifdef _EXPORTING  
#define API_DECLSPEC    __declspec(dllexport)  
#else  
#define API_DECLSPEC    __declspec(dllimport)  
#endif  

#include <QtWidgets/QMainWindow>
#include "ui_TouhouCharacterFigureWidget.h"
#include "TorchModule.h"
class TouhouCharacterFigureWidget : public QMainWindow
{
	Q_OBJECT

public:
	TouhouCharacterFigureWidget(QWidget* parent = Q_NULLPTR);
private:
	Ui::TouhouCharacterFigureWidgetClass ui;
	TorchModule module;
};

#endif//_TCFW_
