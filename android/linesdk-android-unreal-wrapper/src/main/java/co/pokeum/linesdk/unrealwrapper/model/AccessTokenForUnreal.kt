package co.pokeum.linesdk.unrealwrapper.model

import com.google.gson.annotations.SerializedName
import com.linecorp.linesdk.auth.LineLoginResult

data class AccessTokenForUnreal(

    @SerializedName("access_token")
    val accessToken: String,

    @SerializedName("expires_in")
    val expiresIn: Long,

    @SerializedName("id_token")
    val idToken: String = ""
) {

    companion object {
        fun convertFromLineLoginResult(loginResult: LineLoginResult): AccessTokenForUnreal? {
            val lineIdTokenString = loginResult.lineIdToken?.rawString ?: ""
            val accessToken = loginResult.lineCredential?.accessToken ?: return null
            return AccessTokenForUnreal(
                accessToken = accessToken.tokenString,
                expiresIn = accessToken.expiresInMillis,
                idToken = lineIdTokenString
            )
        }
    }
}