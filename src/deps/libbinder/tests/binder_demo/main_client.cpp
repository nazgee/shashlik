// this file contains part of client
#include "utils.hpp"
#include "idkinterface.hpp"
#include "client.hpp"
#include <sys/syscall.h>

#include <binder/IServiceManager.h>

using namespace android;

const char* SERVICE_NAME = "DKService";

int main(int, char**)
{
    LOGD("Client started, pid: %i", getpid());
    // get from servicemanager binder connection to demo server.
    // servicemanager is implemented in /frameworks/native/cmds/servicemanager/
    sp<IBinder> binder = defaultServiceManager()->getService(String16(SERVICE_NAME));
    sp<IDKInterface> server = interface_cast<IDKInterface>(binder);

    //system("dmesg -c > /dev/null");
    //system("logcat -c > /dev/null");
    if (server == 0) {
        LOGD("%s not found, is it running?", SERVICE_NAME);
    } else {
        server->sendInt(0x3F);
        //system("dmesg -c > /dev/null");
        //system("logcat -c > /dev/null");
        server->sendInt(0x3F);
    }
    //system("echo c > /proc/sysrq-trigger");
    //system("dmesg -c > /sdcard/dk_client_dmesg.txt");
    //system("logcat -d > /sdcard/dk_client_logcat.txt");
    //LOGD("Logs saved to /sdcard/");
    return 0;
}
