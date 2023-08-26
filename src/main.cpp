/* cppsrc/main.cpp */


#include "common.h"

#include "value.h"


std::shared_ptr<cling::Interpreter> ntp(nullptr);



Napi::Value Evalulate(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if((ntp.get()) == nullptr)
  {
    Napi::TypeError::New(env, "Cling Is Uninitalized")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if(info.Length() != 1 || !info[0].IsString())
  {
    Napi::TypeError::New(env, "Expected One Argument Of Type String")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  auto arg0 = info[0].As<Napi::String>();

  cling::Value* value = new cling::Value();;

  ntp->process(arg0, value);

  return clingjs::ClingValue::FromClingValue(info.Env(), value);


}

int argc = 1;
char const* argv[] = {"cling"};

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {

    ntp = std::shared_ptr<cling::Interpreter>(new cling::Interpreter(argc, argv));

    exports.Set(Napi::String::New(env, "evaluate"), Napi::Function::New(env, Evalulate));
    clingjs::ClingValue::Init(env, exports);

    return exports;
}

NODE_API_MODULE(addon, InitAll)