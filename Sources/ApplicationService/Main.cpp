#include <iostream>
#include <windows.h>

SERVICE_STATUS ServiceStatus = {};
SERVICE_STATUS_HANDLE ServiceStatusHandle = nullptr;

// Service Name
const char* SERVICE_NAME = "EdgeFuck_Service";

// Function prototypes
void WINAPI ServiceMain(DWORD argc, LPTSTR* argv);
void WINAPI ServiceControlHandler(DWORD controlCode);
void ReportServiceStatus(DWORD currentState, DWORD win32ExitCode, DWORD waitHint);

// Entry point of the program
int main() {
    SERVICE_TABLE_ENTRY ServiceTable[] = {
            { const_cast<LPSTR>(SERVICE_NAME), ServiceMain },
            { nullptr, nullptr }
    };

    // Start the service control dispatcher
    if (!StartServiceCtrlDispatcher(ServiceTable)) {
        std::cerr << "StartServiceCtrlDispatcher failed: " << GetLastError() << std::endl;
        return 1;
    }

    return 0;
}

// The main function of the service
void WINAPI ServiceMain(DWORD argc, LPTSTR* argv) {
    ServiceStatusHandle = RegisterServiceCtrlHandler(SERVICE_NAME, ServiceControlHandler);
    if (!ServiceStatusHandle) {
        return;
    }

    // Initialize the service status structure
    ServiceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
    ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP;
    ServiceStatus.dwCurrentState = SERVICE_START_PENDING;
    ServiceStatus.dwWin32ExitCode = 0;
    ServiceStatus.dwServiceSpecificExitCode = 0;
    ServiceStatus.dwCheckPoint = 0;
    ServiceStatus.dwWaitHint = 0;

    // Report initial status to SCM
    ReportServiceStatus(SERVICE_START_PENDING, NO_ERROR, 3000);

    // Simulate some initialization
    Sleep(2000);

    // Report running status to SCM
    ReportServiceStatus(SERVICE_RUNNING, NO_ERROR, 0);

    // Service running: simulate a work loop
    while (ServiceStatus.dwCurrentState == SERVICE_RUNNING) {
        // Simulate doing some work
        Sleep(1000);
    }

    // Clean up and exit
    ReportServiceStatus(SERVICE_STOPPED, NO_ERROR, 0);
}

// Handles service control requests (e.g., stop)
void WINAPI ServiceControlHandler(DWORD controlCode) {
    switch (controlCode) {
        case SERVICE_CONTROL_STOP:
            ReportServiceStatus(SERVICE_STOP_PENDING, NO_ERROR, 0);
            // Signal the service to stop
            ServiceStatus.dwCurrentState = SERVICE_STOPPED;
            break;
        default:
            break;
    }
}

// Reports the current status of the service to SCM
void ReportServiceStatus(DWORD currentState, DWORD win32ExitCode, DWORD waitHint) {
    ServiceStatus.dwCurrentState = currentState;
    ServiceStatus.dwWin32ExitCode = win32ExitCode;
    ServiceStatus.dwWaitHint = waitHint;

    if (currentState == SERVICE_RUNNING || currentState == SERVICE_STOPPED) {
        ServiceStatus.dwCheckPoint = 0;
    } else {
        ServiceStatus.dwCheckPoint++;
    }

    SetServiceStatus(ServiceStatusHandle, &ServiceStatus);
}