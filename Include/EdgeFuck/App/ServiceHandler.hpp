#ifndef EDGEFUCK_SERVICEHANDLER_HPP
#define EDGEFUCK_SERVICEHANDLER_HPP

#define EdgeFuck_ServiceName "EdgeFuck_Service"
#define EdgeFuck_ServiceDisplayName "EdgeFucker"
#define EdgeFuck_ServiceDefaultExecPath "C:\\EdgeFuck\\EF-Service.exe"

// now, when it comes to me, I'm productive. Productive on a level like this.
#define EdgeFuck_ServiceDescription "Fucks Microsoft Edge into the oblivion"

#include <windows.h>
#include <string>

namespace EdgeFuck {
    void CreateService(const std::string& execPath);

    void DeleteService();

    void StopService();
}

#endif //EDGEFUCK_SERVICEHANDLER_HPP
