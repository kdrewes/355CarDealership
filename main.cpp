#include <wx/wx.h>
#include <wx/grid.h>
#include <wx/listbox.h> // Add this line to include ListBox header
#include <iostream>
#include <mysqlx/xdevapi.h>

#include "./Functions/Read/Sale/sale.h"
#include "./Functions/Read/Employee/employee.h"
#include "./Functions/Read/Customer/customer.h"
#include "./Functions/Read/Vehicle/vehicle.h"




using std::cout;
using std::endl;
using namespace mysqlx;

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    void ConnectToDatabase();
    void CreateNewView();  // New method to create the new view
    void OnMenuSelect(wxCommandEvent& event);

private:
    Session *session;  // Use a pointer for session
    wxPanel *mainPanel;     // Main panel for the new view
    wxListBox* menuList;  // Added menu list
    wxGrid* grid;
    
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame *frame = new MyFrame("Car Dealership App", wxDefaultPosition, wxSize(900, 450));
    frame->Show(true);
    return true;
}

// Updated MyFrame constructor
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    mainPanel = new wxPanel(this);
    vbox->Add(mainPanel, 1, wxEXPAND);

    SetSizer(vbox);
    mainPanel->Hide(); // Initially hide the main panel

    ConnectToDatabase(); // Connect to the database and create the view
}

void MyFrame::ConnectToDatabase() {
    try {
        session = new Session("mysqlx://root:benedict232@127.0.0.1");
        cout << "Connection successful!" << endl;
        mainPanel->Show(); // Show the main panel after successful connection
        CreateNewView(); // Create and show the new view
    }
    catch (const mysqlx::Error &err) {
        wxMessageBox(wxString(err.what()), "Error", wxOK | wxICON_ERROR);
    }
    catch (std::exception &ex) {
        wxMessageBox(wxString(ex.what()), "Exception", wxOK | wxICON_ERROR);
    }
    catch (const char *ex) {
        wxMessageBox(wxString(ex), "Exception", wxOK | wxICON_ERROR);
    }
}

void MyFrame::CreateNewView() {
    // Clear the main panel to prepare for the new view
    mainPanel->DestroyChildren();  // Clear any existing children

    // Use a horizontal sizer to layout menu and grid side by side
    wxBoxSizer* hSizer = new wxBoxSizer(wxHORIZONTAL);

    // Create and add the menu list to the horizontal sizer
    menuList = new wxListBox(mainPanel, wxID_ANY, wxDefaultPosition, wxSize(150, -1));
    menuList->Append("Sales");
    menuList->Append("Employees");
    menuList->Append("Customers");
    menuList->Append("Vehicles");
    menuList->Bind(wxEVT_LISTBOX, &MyFrame::OnMenuSelect, this);
    hSizer->Add(menuList, 0, wxEXPAND | wxALL, 5);

    // Create a wxGrid for displaying the data
    grid = new wxGrid(mainPanel, wxID_ANY);
    // (Configure grid columns and rows as before...)

    hSizer->Add(grid, 1, wxEXPAND | wxALL, 5);

    mainPanel->SetSizer(hSizer);  // Set the horizontal sizer for the main panel
    mainPanel->Layout();  // Layout the main panel

    mainPanel->Show();    // Show the main panel
    this->Layout();       // Update the layout of the frame
    LoadSaleData(mainPanel, session, grid);
}

// Add functionality to highlight the selected table
void MyFrame::OnMenuSelect(wxCommandEvent& event) {
    wxString selectedOption = menuList->GetStringSelection();

    // Change the background color of the selected table to highlight it
    if (selectedOption == "Sales") {
        LoadSaleData(mainPanel, session, grid);  // Load Sales data into the grid
    } else if (selectedOption == "Employees") {
        LoadEmployeeData(mainPanel, session, grid);  // Load Sales data into the grid
    } else if (selectedOption == "Customers") {
        LoadCustomerData(mainPanel, session, grid);
    } else if (selectedOption == "Vehicles") {
        LoadVehicleData(mainPanel, session, grid);
    }
}