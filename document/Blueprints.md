# Blueprints Visual Scripting in Unreal Engine

| <img src="./image/Blueprints/LineSDKBlueprint.png"  width="350"> |
| -- |

## Integrating LINE Login with your Unreal Engine game

### Getting the SDK

1. In your game’s root directory, create a folder named `Plugins`.
2. Copy the [LineSDK](../Line_SDK_Unreal/Plugins/LineSDK) folder into it. You should have something like:

    ```
      MyProject
      ├── Plugins
              └── LineSDK
                  └── LineSDK.uplugin
    ```

3. In a Blueprint Project, enable the plugin by first clicking **Settings** > **Plugins**, scrolling down to Project section of plugins, and clicking **Other** > **LineSDK**. From there you can tick the Enabled checkbox:

    | <img src="./image/Blueprints/EnablePlugin.png"  width="800"> |
    | -- |


### Implement login with LINE

| Login |
| :-- |
| <img src="./image/Blueprints/Login.png"  width="900"> |

| Login With Option |
| :-- |
| <img src="./image/Blueprints/LoginWithOption.png"  width="900"> |

<br/>

## Using LINE SDK for other APIs and result handling

### Calling LINE APIs with result handling

Every LINE SDK for Unreal Engine API operation that can fail, provides a `UResult` object in the callback. By checking the Result value, you can handle both the success and failure case elegantly:

| <img src="./image/Blueprints/Login_Add_ResultListener.png"  width="800"> |
| -- |
| <img src="./image/Blueprints/Login_Add_Result.png"  width="800"> |

| Match | Match Ok | Match Error |
| -- | -- | -- |
| <img src="./image/Blueprints/Match.png"  width="250"> | <img src="./image/Blueprints/MatchOk.png"  width="250"> | <img src="./image/Blueprints/MatchError.png"  width="250"> |

### Getting user profile

| <img src="./image/Blueprints/GetProfile.png"  width="800"> |
| -- |

### Logging out users

| <img src="./image/Blueprints/Logout.png"  width="800"> |
| -- |

### Getting access token

| <img src="./image/Blueprints/GetCurrentAccessToken1.png"  width="800"> |
| -- |

### Verify and refresh access tokens

| Verify Access Token |
| :-- |
| <img src="./image/Blueprints/VerifyAccessToken.png"  width="900"> |

| Refresh Access Token |
| :-- |
| <img src="./image/Blueprints/RefreshAccessToken.png"  width="900"> |
