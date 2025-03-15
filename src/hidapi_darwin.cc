#include "hidapi_darwin.h"

Napi::Value setOpenExclusive(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1)
    {
        Napi::TypeError::New(env, "HIDApiDarwin set_open_exclusive requires one argument").ThrowAsJavaScriptException();
        return env.Null();
    }

    int set_exclusive_status = info[0].As<Napi::Number>().Int32Value();
    int res = hid_darwin_set_open_exclusive(set_exclusive_status);
    if (res < 0)
    {
        Napi::TypeError::New(env, "Error setting set_open_exclusive.").ThrowAsJavaScriptException();
        return env.Null();
    }

    return env.Null();
}