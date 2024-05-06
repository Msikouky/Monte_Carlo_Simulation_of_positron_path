#include "Animation.h"
#include "Trajectory.h"
#include "Point.h"
#include "Visualization.h"
#include "Visualiser.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {

    std::vector <std::string> materialsNames;
    materialsNames.push_back("Water");
    materialsNames.push_back("Lung");
    materialsNames.push_back("Rib Bone");
    
    int materialNumber;
    int simulationNumber;
  
    // Request the user to input Material of choice
    std::cout << "Please choose the corresponding number of the material : \n";
    std::cout << "0: Water \n";
    std::cout << "1: Lung \n";
    std::cout << "2: Rib Bone \n";
    std::cin >> materialNumber;
    //std::getline(std::cin, materialName);

    // Request the user to input the number of the simulation
    std::cout << "Enter the number of the simulation: (from 0 to 9) ";
    std::cin >> simulationNumber;


    //Constructing the file path
    std::string filePath = "../GateData/" + materialsNames[materialNumber] + "/positrons_" + std::to_string(simulationNumber) + "_data.csv";
    std::ifstream file(filePath); 

    if (!file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return -1;
    }

    std::string line;
    std::vector<Trajectory> trajectories;
    std::vector<Point> currentTrajectory;
    double energy;

    // Read each line from the file
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string value;
        double x, y, z;

        // Read the energy value
        getline(iss, value, ',');
        energy = std::stod(value);

        // If energy is zero, start a new trajectory
        if (energy == 0.0) {
            if (!currentTrajectory.empty()) {
                trajectories.emplace_back(currentTrajectory);
                currentTrajectory.clear();
            }
            continue;
        }

        // Read X, Y, Z coordinates
        getline(iss, value, ',');
        x = std::stod(value);
        getline(iss, value, ',');
        y = std::stod(value);
        getline(iss, value);
        z = std::stod(value);

        // Add point to the current trajectory
        currentTrajectory.emplace_back(x, y, z);
    }

    // Add the last trajectory if not empty
    if (!currentTrajectory.empty()) {
        trajectories.emplace_back(currentTrajectory);
    }

    file.close();

    // Create the visualizer and add trajectories
    Visualiser visualiser;
    visualiser.setMaterial(materialsNames[materialNumber]);
    for (auto& trajectory : trajectories) {
        visualiser.addTrajectory(trajectory);
    }

    // Launch visualization
    visualiser.launchVisualization();

    return 0;
}
