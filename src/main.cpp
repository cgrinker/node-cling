/* cppsrc/main.cpp */
#include <napi.h>

#include "cling/Interpreter/Interpreter.h"
#include "cling/MetaProcessor/MetaProcessor.h"
#include "cling/UserInterface/UserInterface.h"
#include "cling/Interpreter/Value.h"

#include "clang/Basic/LangOptions.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/FrontendTool/Utils.h"

#include "llvm/Support/FileSystem.h"
#include "llvm/Support/ManagedStatic.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/PrettyStackTrace.h"
#include "llvm/Support/Signals.h"

#include <memory>

cling::Interpreter* ntp = nullptr;

static std::string ValueToString(const cling::Value& V) {
  std::string valueString;
  {
    llvm::raw_string_ostream os(valueString);
    V.print(os);
  }
  return valueString;
}

Napi::Value Evalulate(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if(ntp == nullptr)
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

  cling::Value value;

  ntp->process(arg0, &value);

  if(value.isValid())
  {
    auto res = ValueToString(value);
    return Napi::String::New(env, res.c_str());
  }
  else {
    return env.Null();
  }

}

int argc = 1;
char const* argv[] = {"cling"};

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {

    ntp = new cling::Interpreter(argc, argv);

    exports.Set(Napi::String::New(env, "evaluate"), Napi::Function::New(env, Evalulate));

    return exports;
}

NODE_API_MODULE(addon, InitAll)