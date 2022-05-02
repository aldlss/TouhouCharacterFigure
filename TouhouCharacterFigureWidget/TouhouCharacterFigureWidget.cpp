#include "TouhouCharacterFigureWidget.h"
#include "QToolButton"
#include "QFileDialog"

TouhouCharacterFigureWidget::TouhouCharacterFigureWidget(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.toolButton_5, &QToolButton::clicked, [&]()->void {
		QString inFoldName{};
		inFoldName = QFileDialog::getExistingDirectory(this, QString::fromLocal8Bit("选择输入文件夹"));
		ui.lineEdit_5->setText(inFoldName);
		});
	connect(ui.toolButton_7, &QToolButton::clicked, [&]()->void {
		QString outFoldName{};
		outFoldName = QFileDialog::getExistingDirectory(this, QString::fromLocal8Bit("选择输出文件夹"));
		ui.lineEdit_7->setText(outFoldName);
		});
	connect(ui.toolButton, &QToolButton::clicked, [&]()->void {
		QString modelFileName{};
		modelFileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择模型文件"), "", "Torch Model(*.pt);;All File(*.*)");
		ui.lineEdit_7->setText(modelFileName);
		});
	connect(ui.toolButton_6, &QToolButton::clicked, [&]()->void {
		QString labelFileName{};
		labelFileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择标签文件"), "", "Label Text(*.txt);;All File(*.*)");
		ui.lineEdit_6->setText(labelFileName);
		});
	// connect(ui.pushButton, &QPushButton::clicked, [&]()->void {
	// 	// module.setImgsFolderRoute(ui.lineEdit_7->text().toStdString());
	// 	// module.setLabel()
	// 	});
}


