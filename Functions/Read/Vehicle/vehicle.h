// SaleDataLoader.h
#ifndef VEHICLE_DATA_LOADER_H
#define VEHICLE_DATA_LOADER_H

#include <wx/wx.h>
#include <wx/grid.h>
#include <mysqlx/xdevapi.h>

using namespace mysqlx;

void LoadVehicleData(wxPanel* mainPanel, Session* session, wxGrid*& grid);

#endif // VEHICLE_DATA_LOADER_H