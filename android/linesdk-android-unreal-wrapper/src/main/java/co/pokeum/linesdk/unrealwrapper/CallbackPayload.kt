package co.pokeum.linesdk.unrealwrapper

import co.pokeum.linesdk.unreal.UnrealBridge
import co.pokeum.linesdk.unrealwrapper.model.ErrorForUnreal
import com.google.gson.Gson
import com.linecorp.linesdk.LineApiResponse
import com.linecorp.linesdk.auth.LineLoginResult

data class CallbackPayload(
    val identifier: String,
    val value: String
) {
    fun sendMessageOk() = UnrealBridge.sendMessage(API_OK, generatePayloadJson())
    fun sendMessageError() = UnrealBridge.sendMessage(API_ERROR, generatePayloadJson())

    private fun generatePayloadJson(): String = gson.toJson(this)

    companion object {
        private val gson: Gson = Gson()

        private const val API_OK: Int       = 0
        private const val API_ERROR: Int    = 1

        fun <T> sendMessageError(
            identifier: String,
            lineApiResponse: LineApiResponse<T>
        ) {
            val error = getErrorJsonString(lineApiResponse)
            CallbackPayload(identifier, error).sendMessageError()
        }

        fun sendMessageError(
            identifier: String,
            loginResult: LineLoginResult,
            errorString: String
        ) {
            val errorForUnity = ErrorForUnreal(loginResult.responseCode.ordinal, errorString)
            CallbackPayload(identifier, gson.toJson(errorForUnity)).sendMessageError()
        }

        private fun <T> getErrorJsonString(lineApiResponse: LineApiResponse<T>): String {
            val error = ErrorForUnreal(
                lineApiResponse.responseCode.ordinal,
                lineApiResponse.errorData.message ?: "error"
            )
            return gson.toJson(error)
        }
    }
}
