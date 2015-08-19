// this is server main
#include "server.hpp"

#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

using namespace android;

const char* SERVICE_NAME = "DKService";

int main(int, char**)
{
    LOGD("Server started, pid: %i", getpid());
    // get servicemanager and new service
    defaultServiceManager()->addService(String16(SERVICE_NAME), new DKServer());
    // this is regular android part, I don't really know what it is doing,
    // but this is not related to binder
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
    return 0;
}
