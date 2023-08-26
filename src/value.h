#pragma once

#include "common.h"


namespace clingjs {
    class ClingValue : public Napi::ObjectWrap<ClingValue> {

    private:
        cling::Value* _value;
        
    public:
        

        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        ClingValue(const Napi::CallbackInfo& info);
        ~ClingValue();

        static Napi::Value FromClingValue(Napi::Env env, cling::Value* value);
 
        Napi::Value toString(const Napi::CallbackInfo& info);

    private:
        
    };
}