package co.pokeum.linesdk.unrealwrapper

import android.app.Activity
import android.content.Context
import android.util.Log
import co.pokeum.linesdk.unrealwrapper.CallbackPayload.Companion.sendMessageError
import co.pokeum.linesdk.unrealwrapper.activity.LineSdkWrapperActivity
import co.pokeum.linesdk.unrealwrapper.model.AccessTokenForUnreal
import co.pokeum.linesdk.unrealwrapper.model.BotFriendshipStatus
import co.pokeum.linesdk.unrealwrapper.model.UserProfile
import co.pokeum.linesdk.unrealwrapper.model.VerifyAccessTokenResult
import com.google.gson.Gson
import com.linecorp.linesdk.Scope
import com.linecorp.linesdk.api.LineApiClient
import com.linecorp.linesdk.api.LineApiClientBuilder
import com.linecorp.linesdk.auth.LineAuthenticationParams

object LineSdkWrapper {

    private const val TAG: String = "LineSdkWrapper"

    private lateinit var lineApiClient: LineApiClient
    private lateinit var channelId: String
    private val gson = Gson()

    @JvmStatic
    fun setupSdk(applicationContext: Context, channelId: String) {
        Log.d(TAG, "setupSdk")

        this.channelId = channelId
        lineApiClient = LineApiClientBuilder(applicationContext, channelId).build()
    }

    @JvmStatic
    fun login(
        activity: Activity,
        identifier: String,
        scope: String,
        onlyWebLogin: Boolean,
        botPrompt: String?,
        tokenNonce: String?
    ) {
        Log.d(TAG, "login")
        Log.d(TAG, "channelId:$channelId")
        Log.d(TAG, "scope:$scope")

        LineSdkWrapperActivity.startActivity(
            activity = activity,
            identifier = identifier,
            channelId = channelId,
            scope = scope,
            onlyWebLogin = onlyWebLogin,
            botPrompt = botPrompt ?: LineAuthenticationParams.BotPrompt.normal.name,
            tokenNonce = tokenNonce
        )
    }

    @JvmStatic
    fun getProfile(identifier: String) {
        Log.d(TAG, "getProfile")
        val profile = lineApiClient.profile
        if (!profile.isSuccess) {
            sendMessageError(identifier, profile)
            return
        }

        val profileData = lineApiClient.profile.responseData
        val userProfile = UserProfile.convertLineProfile(profileData)
        val jsonString = gson.toJson(userProfile)
        Log.d(TAG, "getProfile: $jsonString")
        CallbackPayload(identifier, jsonString).sendMessageOk()
    }

    @JvmStatic
    fun getCurrentAccessToken(): String {
        val tokenResponse = lineApiClient.currentAccessToken
        return if (tokenResponse.isSuccess) {
            val accessToken = AccessTokenForUnreal(
                accessToken = tokenResponse.responseData.tokenString,
                expiresIn = tokenResponse.responseData.expiresInMillis
            )
            gson.toJson(accessToken)
        } else {
            Log.e(TAG, "getCurrentAccessToken failed: errorCode: ${tokenResponse.responseCode}")
            ""
        }
    }

    @JvmStatic
    fun logout(identifier: String) {
        Log.d(TAG, "logout")
        lineApiClient.logout()
        CallbackPayload(identifier, "").sendMessageOk()
    }

    @JvmStatic
    fun getBotFriendshipStatus(identifier: String) {
        Log.d(TAG, "getBotFriendShipStatus")
        val friendshipStatus = lineApiClient.friendshipStatus
        if (!friendshipStatus.isSuccess) {
            sendMessageError(identifier, friendshipStatus)
            return
        }

        val botFriendShipStatus =
            BotFriendshipStatus(lineApiClient.friendshipStatus.responseData.isFriend)
        CallbackPayload(identifier, gson.toJson(botFriendShipStatus)).sendMessageOk()
    }

    @JvmStatic
    fun refreshAccessToken(identifier: String) {
        Log.d(TAG, "refreshAccessToken")

        val lineApiResponse = lineApiClient.refreshAccessToken()
        if (!lineApiResponse.isSuccess) {
            sendMessageError(identifier, lineApiResponse)
            return
        }

        val accessToken = AccessTokenForUnreal(
            accessToken = lineApiResponse.responseData.tokenString,
            expiresIn = lineApiResponse.responseData.expiresInMillis
        )

        CallbackPayload(identifier, gson.toJson(accessToken)).sendMessageOk()
    }

    @JvmStatic
    fun verifyAccessToken(identifier: String) {
        Log.d(TAG, "verifyAccessToken")
        val lineApiResponse = lineApiClient.verifyToken()
        if (!lineApiResponse.isSuccess) {
            sendMessageError(identifier, lineApiResponse)
            return
        }

        val lineCredential = lineApiResponse.responseData
        val scopeString = Scope.join(lineCredential.scopes)
        val verifyAccessTokenResult = VerifyAccessTokenResult(
            channelId = channelId,
            scope = scopeString,
            expireIn = lineCredential.accessToken.expiresInMillis
        )

        CallbackPayload(identifier, gson.toJson(verifyAccessTokenResult)).sendMessageOk()
    }
}