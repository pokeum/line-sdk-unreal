package co.pokeum.linesdk.unrealwrapper.model

import com.google.gson.annotations.SerializedName

data class VerifyAccessTokenResult(

    @SerializedName("client_id")
    val channelId: String,

    @SerializedName("scope")
    val scope: String,

    @SerializedName("expire_in")
    val expireIn: Long
)
