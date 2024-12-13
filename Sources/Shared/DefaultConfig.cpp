#include "EdgeFuck/Shared/DefaultConfig.hpp"

std::vector<BrowserSelectionItem> defaultBrowserSelectionItems = {
        {
            "Firefox",
            "A fast, privacy-focused open-source browser",
            "en_US",
            "https://download.mozilla.org/?product=firefox-latest-ssl&os=win64&lang={lang_code}",
            "latest",
            true,
            DOWNLOAD
        },
        {
            "Google Chrome",
            "Google's widely-used browser known for performance and features",
            std::nullopt,
            "https://www.google.com/intl/de/chrome/",
            "latest",
            true,
            OPEN_LINK
        },
        {
            "Chromium",
            "The open-source base for Chrome, with minimal features",
            std::nullopt,
            "https://storage.googleapis.com/chromium-browser-snapshots/Win_x64/{version}/mini_installer.exe",
            "1395822",
            true,
            DOWNLOAD
        },
        {
            "Brave",
            "A privacy-first browser with built-in ad and tracker blocking",
            std::nullopt,
            "https://referrals.brave.com/latest/BraveBrowserSetup.exe",
            "latest",
            true,
            DOWNLOAD
        },
        {
            "Opera",
            "A beautiful browser with a pretty sidebar and a free VPN",
            std::nullopt,
            "https://download.opera.com/download/get/?id=69054&location=415&nothanks=yes&sub=marine",
            "latest",
            true,
            DOWNLOAD
        },
        {
            "Opera GX",
            "A gaming-focused browser with customization and resource control",
            std::nullopt,
            "https://net.geo.opera.com/opera_gx/stable/windows?utm_source=google&utm_medium=ose&utm_campaign=%28none%29&http_referrer=https%3A%2F%2Fwww.google.com%2F&utm_site=opera_com&utm_lastpage=opera.com%2Fgx",
            "latest",
            true,
            DOWNLOAD
        }
};

std::vector<BrowserSelectionItem> browserSelectionItems = {};