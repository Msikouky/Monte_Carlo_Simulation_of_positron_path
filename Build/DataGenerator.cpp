#include <iostream>
#include <vector>
#include"DataGenerator.h"
#include <vtkChartXY.h>
#include <vtkContextView.h>
#include <vtkFloatArray.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPlot.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkTable.h>


DataGenerator::DataGenerator() {}

DataGenerator::DataGenerator(const DataGenerator& dg) {
	this->setPoints(dg._dataPoints);
	this->setPointsToVtk(dg._dataPoints); 
}

void DataGenerator::setPoints(const std::vector<Point>& points) {

	// Assign the vector of points we create to dataPoints
	_dataPoints = points;
}

std::vector<Point> DataGenerator::getPoints() {
	return _dataPoints;
}

DataGenerator& DataGenerator:: operator=(const DataGenerator& dg) {
	this->setPoints(dg._dataPoints);
	this->setPointsToVtk(dg._dataPoints);
	return *this;
}

void DataGenerator::printPoints() {
	for (int i{}; i < _dataPoints.size(); ++i) {
		_dataPoints[i].print();
	}
}

void DataGenerator::setPointsToVtk(const std::vector<Point>& points) {
	for (int i{}; i < _dataPoints.size(); ++i) {
		_pointsToVtk->InsertNextPoint(_dataPoints[i].getX(), _dataPoints[i].getY(), _dataPoints[i].getZ());
	}
}


void DataGenerator::drawHistogram() {

	vtkNew<vtkNamedColors> colors;

	//Create a table with some points in it
	vtkNew<vtkTable> table;
	
	vtkNew<vtkFloatArray> arrX;
	arrX->SetName("X Axis");
	table->AddColumn(arrX);

	vtkNew<vtkFloatArray> arrY;
	arrY->SetName("Y Axis");
	table->AddColumn(arrY);

	//Fill in the table with some example values
	table->SetNumberOfRows(_dataPoints.size());
	for (int i{}; i < _dataPoints.size(); ++i) {
		table->SetValue(i, 0, _dataPoints[i].getX());
		table->SetValue(i, 1, _dataPoints[i].getY());
	}
	
	//Set up the view
	vtkNew<vtkContextView> view;
	view->GetRenderWindow()->SetWindowName("Histogram");
	view->GetRenderer()->SetBackground(colors->GetColor3d("White").GetData());
	
	//Add Line Plot
	vtkNew<vtkChartXY> chart;
	view->GetScene()->AddItem(chart); 
	
	vtkPlot* line = chart->AddPlot(vtkChart::LINE);
	line->SetInputData(table, 0, 1);
	line->SetColor(0, 0, 0);
	line->SetWidth(1.0);

	view->GetRenderWindow()->SetMultiSamples(0);
	
	// Start interactor
	view->GetRenderWindow()->Render(); 
	view->GetInteractor()->Initialize();
	view->GetInteractor()->Start(); 

}



