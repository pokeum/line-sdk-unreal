package co.pokeum.linesdk.unrealwrapper

import co.pokeum.linesdk.unrealwrapper.model.ErrorForUnreal
import com.google.gson.Gson

object Helpers {

    fun isInvalidRuntime(identifier: String) {
        val errorForUnity = ErrorForUnreal(
            code = -1,
            message = "platform not supported."
        )
        CallbackPayload(identifier, Gson().toJson(errorForUnity)).sendMessageError()
    }
}