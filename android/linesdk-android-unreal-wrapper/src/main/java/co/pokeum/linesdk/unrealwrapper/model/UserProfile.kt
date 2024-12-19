package co.pokeum.linesdk.unrealwrapper.model

import com.linecorp.linesdk.LineProfile

data class UserProfile(
    val userId: String,
    val displayName: String,
    val pictureUrl: String,
    val statusMessage: String
) {
    companion object {
        fun convertLineProfile(profile: LineProfile) = UserProfile(
            userId = profile.userId,
            displayName = profile.displayName,
            pictureUrl = profile.pictureUrl?.toString() ?: "",
            statusMessage = profile.statusMessage ?: ""
        )
    }
}

