#ifndef EDGEFUCK_DEFAULTCONFIG_HPP
#define EDGEFUCK_DEFAULTCONFIG_HPP

#define Process_InstallDir "{WinInstallLetter}\\EdgeFuck"
#define Process_InstallFallbackDir "{UserHome}\\AppData\\Roaming\\EdgeFuck\\Logs"
#define Process_ServiceExecFile "EF-Service.exe"
#define Process_DetectBrowserInstallations true
#define Process_CreateService true

#define Service_StartType "Automatic"
#define Service_StartWhen "Boot"
#define Service_Logging true
#define Service_LogPath "{Process_InstallDir}\\Logs"

#define Browser_DefaultInstaller "prompt"
#define Browser_PromptIf "!edge_alternative.found"
#define Browser_DownloadAutoExec true
#define Browser_SelectionList "Firefox; Chrome; Chromium; Brave; Opera; Opera GX"

#include <vector>
#include <string>
#include <optional>

enum BrowserExecMethod {
    OPEN_LINK = 1,
    DOWNLOAD = 0
};

struct BrowserSelectionItem {
    std::string name;
    std::string desc;
    std::optional<std::string> langCode;
    std::string link;
    std::string version;
    bool follow3XX = true;
    BrowserExecMethod exec;
};

extern std::vector<BrowserSelectionItem> defaultBrowserSelectionItems;
extern std::vector<BrowserSelectionItem> browserSelectionItems;

#endif //EDGEFUCK_DEFAULTCONFIG_HPP
