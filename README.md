<img src="document/image/UNOFFICIAL_Line_SDK_icon.png"  width="254">   

# [⚠️ UNOFFICIAL] LINE SDK for Unreal

[![line/line-sdk-android](https://img.shields.io/badge/GitHub-line/line--sdk--android-51A687?logo=github&logoColor=white)](https://github.com/line/line-sdk-android)
[![line/line-sdk-unity](https://img.shields.io/badge/GitHub-line/line--sdk--unity-51A687?logo=github&logoColor=white)](https://github.com/line/line-sdk-unity)

Implemented SDK versions:

- [`com.linecorp.linesdk:linesdk:5.10.1`](https://mvnrepository.com/artifact/com.linecorp.linesdk/linesdk/5.10.1)

## Overview

This repo contains the _**⚠️ UNOFFICIAL** LINE SDK_ for Unreal Engine. It allows you to use LINE Login and LINE API in your Unity games easier.

## Features

The LINE SDK for Unreal Engine provides the following features.

### User authentication

This feature allows users to log in to your service with their LINE accounts. With the help of the LINE SDK for Unreal Engine, it has never been easier to integrate LINE Login into your app. Your users will automatically log in to your app without entering their LINE credentials if they are already logged in to LINE on their <del>iOS</del>_(not yet supported)_/Android devices. This offers a great way for users to get started with your app without having to go through a registration process.

### Utilizing user data with OpenID support

Once the user authorizes, you can get the user’s LINE profile. You can utilize the user's information registered in LINE without building your user system.

The LINE SDK supports the OpenID Connect 1.0 specification. You can get ID tokens that contain the user’s LINE profile when you retrieve the access token.

## Using the SDK

### Prerequisites

* Android `minSdkVersion` set to 24 or higher (Android 7.0 or later).

> [!NOTE]
> Setting Up Android Minimum SDK Version for Unreal
> | <img src="document/image/readme_minSdkVersion_24.png"  width="650"> |
> | --- |

* Unreal Engine 4.23 or later.

## Troubleshooting

### Android

#### 1. Using `AndroidX`

>  [![AndroidX](https://img.shields.io/badge/Android_Developers-AndroidX_overview-a4c639?logo=android&logoColor=white&style=for-the-badge)](https://developer.android.com/jetpack/androidx)
> 
> In Unreal Engine v4.23 or later and v5.1.0 or earlier, write the following Unreal Plugin Language code.
> 
> ```xml
> <?xml version="1.0" encoding="utf-8"?>
> <root xmlns:android="http://schemas.android.com/apk/res/android">
> 
>     <gradleProperties>
>         <insert>
>             android.useAndroidX=true
>             android.enableJetifier=true
>         </insert>
>     </gradleProperties>
> 
>     <baseBuildGradleAdditions>
>         <insert>
>             allprojects {
> 
>                 def classMap = [
>                     'android.support.annotation': 'androidx.annotation',
>                     'android.support.v4.app.ActivityCompat': 'androidx.core.app.ActivityCompat',
>                     'android.support.v4.app.NotificationCompat': 'androidx.core.app.NotificationCompat',
>                     'android.support.v4.app.NotificationManagerCompat': 'androidx.core.app.NotificationManagerCompat',
>                     'android.support.v4.content.ContextCompat': 'androidx.core.content.ContextCompat',
>                     'android.support.v4.content.FileProvider': 'androidx.core.content.FileProvider',
>                     'android.support.v13.app.FragmentCompat': 'androidx.legacy.app.FragmentCompat',
>                     'android.arch.lifecycle': 'androidx.lifecycle',
>                     'android.arch.lifecycle.Lifecycle': 'androidx.lifecycle.Lifecycle',
>                     'android.arch.lifecycle.LifecycleObserver': 'androidx.lifecycle.LifecycleObserver',
>                     'android.arch.lifecycle.OnLifecycleEvent': 'androidx.lifecycle.OnLifecycleEvent',
>                     'android.arch.lifecycle.ProcessLifecycleOwner': 'androidx.lifecycle.ProcessLifecycleOwner',
>                 ]
>     
>                 afterEvaluate { project ->
>                     project.rootProject.projectDir.traverse(type: groovy.io.FileType.FILES, nameFilter: ~/.*\.java$/) { f ->
>                         classMap.each { entry ->
>                             if (f.getText('UTF-8').contains(entry.key)) {
>                                 println "Change ${entry.key} to ${entry.value} in file ${f}"
>                                 ant.replace(file: f, token: entry.key, value: entry.value)
>                             }
>                         }
>                     }
>                 }
>             }
>         </insert>
>     </baseBuildGradleAdditions>
> </root>
> ```
