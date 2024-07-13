#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

#include <base64.h>

std::vector<std::string> find_files(const fs::path& path) {
    std::vector<std::string> file_formats = {
        ".DOC", ".DOCX", ".XLS", ".XLSX", ".PPT", ".PPTX", ".PST", ".OST", ".MSG", ".EML", ".VSD",
        ".VSDX", ".TXT", ".CSV", ".RTF", ".WKS", ".WK1", ".PDF", ".DWG", ".ONETOC2", ".SNT",
        ".JPEG", ".JPG", ".DOCB", ".DOCM", ".DOT", ".DOTM", ".DOTX", ".XLSM", ".XLSB", ".XLW",
        ".XLT", ".XLM", ".XLC", ".XLTX", ".XLTM", ".PPTM", ".POT", ".PPS", ".PPSM", ".PPSX",
        ".PPAM", ".POTX", ".POTM", ".EDB", ".HWP", ".602", ".SXI", ".STI", ".SLDX", ".SLDM",
        ".VDI", ".VMDK", ".VMX", ".GPG", ".AES", ".ARC", ".PAQ", ".BZ2", ".TBK", ".BAK", ".TAR",
        ".TGZ", ".GZ", ".7Z", ".RAR", ".ZIP", ".BACKUP", ".ISO", ".VCD", ".BMP", ".PNG", ".GIF",
        ".RAW", ".CGM", ".TIF", ".TIFF", ".NEF", ".PSD", ".AI", ".SVG", ".DJVU", ".M4U", ".M3U",
        ".MID", ".WMA", ".FLV", ".3G2", ".MKV", ".3GP", ".MP4", ".MOV", ".AVI", ".ASF", ".MPEG",
        ".VOB", ".MPG", ".WMV", ".FLA", ".SWF", ".WAV", ".MP3", ".SH", ".CLASS", ".JAR", ".JAVA",
        ".RB", ".ASP", ".PHP", ".JSP", ".BRD", ".SCH", ".DCH", ".DIP", ".PL", ".VB", ".VBS",
        ".PS1", ".BAT", ".CMD", ".JS", ".ASM", ".H", ".PAS", ".CPP", ".C", ".CS", ".SUO",
        ".SLN", ".LDF", ".MDF", ".IBD", ".MYI", ".MYD", ".FRM", ".ODB", ".DBF", ".DB", ".MDB",
        ".ACCDB", ".SQL", ".SQLITEDB", ".SQLITE3", ".ASC", ".LAY6", ".LAY", ".MML", ".SXM",
        ".OTG", ".ODG", ".UOP", ".STD", ".SXD", ".OTP", ".ODP", ".WB2", ".SLK", ".DIF", ".STC",
        ".SXC", ".OTS", ".ODS", ".3DM", ".MAX", ".3DS", ".UOT", ".STW", ".SXW", ".OTT", ".ODT",
        ".PEM", ".P12", ".CSR", ".CRT", ".KEY", ".PFX", ".DER"
    };

    std::vector<std::string> files;
    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        if (entry.is_regular_file()) {
            std::string extension = entry.path().extension().string();
            std::transform(extension.begin(), extension.end(), extension.begin(), ::toupper);
            if (std::find(file_formats.begin(), file_formats.end(), extension)!= file_formats.end() || extension.empty()) {
                std::string file_path = entry.path().string();
                std::string encoded_path = base64_encode(file_path);
                files.push_back(encoded_path);
            }
        }
    }
    return files;
}

int main() {
    fs::path path("/home/tarcisio/teste");
    for (const auto& file : find_files(path)) {
        std::cout << file << std::endl;
    }
    return 0;
}