package co.pokeum.linesdk.unrealwrapper.model

import com.linecorp.linesdk.Scope
import com.linecorp.linesdk.auth.LineLoginResult

data class LoginResultForUnreal(
    val accessToken: AccessTokenForUnreal,
    val scope: String,
    val userProfile: UserProfile?,
    val friendshipStatusChanged: Boolean,
    val IDTokenNonce: String?
) {
    companion object {
        fun convertLineResult(lineLoginResult: LineLoginResult): LoginResultForUnreal? {
            val accessToken = AccessTokenForUnreal.convertFromLineLoginResult(lineLoginResult) ?: return null
            val lineProfile = lineLoginResult.lineProfile?.let { UserProfile.convertLineProfile(it) }
            val scope = lineLoginResult.lineCredential?.scopes?.let { Scope.join(it) } ?: ""
            return LoginResultForUnreal(
                accessToken = accessToken,
                scope = scope,
                userProfile = lineProfile,
                friendshipStatusChanged = lineLoginResult.friendshipStatusChanged,
                IDTokenNonce = lineLoginResult.nonce
            )
        }
    }
}

