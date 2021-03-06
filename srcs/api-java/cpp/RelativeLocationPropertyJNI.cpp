/*
 * This file is part of Nokia HEIF library
 *
 * Copyright (c) 2015-2018 Nokia Corporation and/or its subsidiary(-ies). All rights reserved.
 *
 * Contact: heif@nokia.com
 *
 * This software, including documentation, is protected by copyright controlled by Nokia Corporation and/ or its
 * subsidiaries. All rights are reserved. Copying, including reproducing, storing, adapting or translating, any or all
 * of this material requires the prior written consent of Nokia.
 *
 *
 */

#include <DescriptiveProperty.h>
#include <jni.h>
#include "Helpers.h"

#define CLASS_NAME RelativeLocationProperty

extern "C"
{
    JNI_METHOD_ARG(jlong, createContextNative, jobject javaHEIF)
    {
        NATIVE_HEIF(nativeHeif, javaHEIF);
        HEIFPP::RelativeLocationProperty *nativeObject = new HEIFPP::RelativeLocationProperty(nativeHeif);
        nativeObject->setContext(static_cast<void*>(env->NewGlobalRef(self)));
        return reinterpret_cast<jlong>(nativeObject);
    }

    JNI_METHOD_ARG(void, setHorizontalOffsetNative, jint offset)
    {
        NATIVE_RELATIVE_LOCATION_PROPERTY(nativeHandle, self);
        nativeHandle->mRelativeLocation.horizontalOffset = static_cast<uint32_t>(offset);
    }

    JNI_METHOD_ARG(void, setVerticalOffsetNative, jint offset)
    {
        NATIVE_RELATIVE_LOCATION_PROPERTY(nativeHandle, self);
        nativeHandle->mRelativeLocation.verticalOffset = static_cast<uint32_t>(offset);
    }

    JNI_METHOD(int, getHorizontalOffsetNative)
    {
        NATIVE_RELATIVE_LOCATION_PROPERTY(nativeHandle, self);
        return static_cast<jint>(nativeHandle->mRelativeLocation.horizontalOffset);
    }

    JNI_METHOD(int, getVerticalOffsetNative)
    {
        NATIVE_RELATIVE_LOCATION_PROPERTY(nativeHandle, self);
        return static_cast<jint>(nativeHandle->mRelativeLocation.verticalOffset);
    }
}
