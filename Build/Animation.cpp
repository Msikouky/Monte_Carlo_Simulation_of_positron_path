//#include "Animation.h"
//
//
////void Animation::Execute(vtkObject* caller, unsigned long eventId, void* callData) {
////
////	std::cout << "Launching the Exceuction function in Animation " << "\n";
////	double t = vtkMath::ClampValue(this->AnimationParameter, 0.0, 1.0);
////	
////	//Calculate the index of the last point to be drawn
////	int endIndex = static_cast<int>(t * (_trajectory->getDataPoints().size() - 1));
////	std::cout << "endIndex = : " << endIndex << "\n";
////	std::cout << "In Execuste function in animation class: this trajectory length is : " << _trajectory->getDataPoints().size() << "\n";
////	
////	//Create the vector that stores the points to be drawn
////	//std::vector<Point> pointstoDraw(_trajectory->getDataPoints().begin(), _trajectory->getDataPoints().begin() + endIndex + 1);
////
////	//Create a polyData for the points to be drawn
////
////	//vtkSmartPointer<vtkPolyData> polylineData = _trajectory->CreatePolyLine(); 
////	//this->_PolylineMapper->SetInputData(polylineData); 
////	_trajectory->setPolylineMapper();
////	this->_PolylineMapper = _trajectory->getPolylineMapper();
////	this->_PolylineMapper->Update();
////
////	//Update the rendering window (ensure that the updated line versions are displayed on the screen)
////	this->_renderWindowInteractor->GetRenderWindow()->Render();
////
////	//Update the animation parameter
////	this->AnimationParameter += this->step;
////
////	//Stop the animation if all points have been drawn
////	if (endIndex >=static_cast<int>(_trajectory->getDataPoints().size() -1)) {
////		//this->AnimationParameter = 0.0;
////		return;
////	}
////
////}
//
//void Animation::Execute(vtkObject* caller, unsigned long eventId, void* callData) {
//    double t = vtkMath::ClampValue(this->AnimationParameter, 0.0, 1.0);
//
//    // Calculate the index of the last point to be drawn
//    int endIndex = static_cast<int>(t * (_trajectory->getDataPoints().size() - 1));
//
//    // Create a polyData for the points to be drawn
//    vtkSmartPointer<vtkPolyData> polylineData = vtkSmartPointer<vtkPolyData>::New();
//    vtkNew<vtkPoints> vtkPoints;
//    vtkNew<vtkCellArray> lines;
//
//    // Insert points into vtkPoints and lines into cell array up to endIndex
//    for (int i = 0; i <= endIndex; ++i) {
//        std::cout << "endIndex = :" << endIndex << "\n";
//        const auto& point = _trajectory->getDataPoints()[i];
//        vtkIdType id = vtkPoints->InsertNextPoint(point.getX(), point.getY(), point.getZ());
//        lines->InsertNextCell(1, &id);
//    }
//
//    polylineData->SetPoints(vtkPoints);
//    polylineData->SetLines(lines);
//
//    // Update the polyline mapper with the new polyData
//    this->_PolylineMapper->SetInputData(polylineData);
//    this->_PolylineMapper->Update();
//
//    // Update the rendering window (ensure that the updated line versions are displayed on the screen)
//    this->_renderWindowInteractor->GetRenderWindow()->Render();
//
//    // Update the animation parameter
//    this->AnimationParameter += this->step;
//
//    // Stop the animation if all points have been drawn
//    if (endIndex >= static_cast<int>(_trajectory->getDataPoints().size() - 1)) {
//        // Reset the animation parameter and stop the animation
//        this->AnimationParameter = 0.0;
//        this->_renderWindowInteractor->DestroyTimer();
//    }
//}
