package co.pokeum.linesdk.activity;

import static co.pokeum.linesdk.InputsDialogConstant.KEY_BOT_PROMPT;
import static co.pokeum.linesdk.InputsDialogConstant.KEY_ONLY_WEB_LOGIN;
import static co.pokeum.linesdk.InputsDialogConstant.KEY_SCOPE;
import static co.pokeum.linesdk.InputsDialogConstant.KEY_TOKEN_NONCE;
import static co.pokeum.linesdk.InputsDialogConstant.LISTENER_ID_LOGIN;

import android.content.DialogInterface;
import android.util.Log;
import android.widget.Toast;

import androidx.annotation.NonNull;

import java.util.ArrayList;
import java.util.UUID;

import co.pokeum.inputs.dialog.InputsDialogFragment;
import co.pokeum.inputs.dialog.InputsDialogInterface;
import co.pokeum.inputs.dialog.model.InputModel;
import co.pokeum.inputs.dialog.model.InputModelBuilder;
import co.pokeum.inputs.dialog.model.InputModelType;
import co.pokeum.inputs.dialog.model.ResultModel;
import co.pokeum.linesdk.R;

public class TestUI extends UPL implements InputsDialogInterface.ResultListener {

    private String newGuid() {
        return UUID.randomUUID().toString();
    }

    public void initUI() {

        binding.btnSetupSdk.setOnClickListener(view -> {
            lineSdk_setupSdk(getString(R.string.channel_id));
        });

        binding.btnLogin.setOnClickListener(view -> {
            new InputsDialogFragment.Builder()
                    .setTitle("Login")
                    .setInputs(new ArrayList<InputModel>() {{
                        add(new InputModelBuilder(KEY_SCOPE, InputModelType.KeyValue)
                                .setLabel("Scope")
                                .setDefaultValue("profile")
                                .setValueContentDescription("scope")
                                .build());
                        add(new InputModelBuilder(KEY_ONLY_WEB_LOGIN, InputModelType.KeyValue)
                                .setLabel("Only Web Login")
                                .setDefaultValue("false")
                                .setValueContentDescription("onlyWebLogin")
                                .build());
                        add(new InputModelBuilder(KEY_BOT_PROMPT, InputModelType.KeyValue)
                                .setLabel("Bot Prompt")
                                .setValueContentDescription("botPrompt")
                                .build());
                        add(new InputModelBuilder(KEY_TOKEN_NONCE, InputModelType.KeyValue)
                                .setLabel("Token Nonce")
                                .setValueContentDescription("tokenNonce")
                                .build());
                    }})
                    .setListener(this)
                    .setListenerId(LISTENER_ID_LOGIN)
                    .build()
                    .show(getSupportFragmentManager());
        });

        binding.btnGetProfile.setOnClickListener(view -> {
            String identifier = newGuid();
            Log.d(LINE_SDK_TAG, "'Get Profile' button clicked with identifier={" + identifier + "}");
            lineSdk_getProfile(identifier);
        });

        binding.btnGetCurrentAccessToken.setOnClickListener(view -> {
            Log.d(LINE_SDK_TAG, "'Get Current Access Token' button clicked");
            String accessToken = lineSdk_getCurrentAccessToken();
            Toast.makeText(this, accessToken, Toast.LENGTH_LONG).show();
        });

        binding.btnLogout.setOnClickListener(view -> {
            String identifier = newGuid();
            Log.d(LINE_SDK_TAG, "'Logout' button clicked with identifier={" + identifier + "}");
            lineSdk_logout(identifier);
        });

        binding.btnGetBotFriendshipStatus.setOnClickListener(view -> {
            String identifier = newGuid();
            Log.d(LINE_SDK_TAG, "'Get Bot Friendship Status' button clicked with identifier={" + identifier + "}");
            lineSdk_getBotFriendshipStatus(identifier);
        });

        binding.btnRefreshAccessToken.setOnClickListener(view -> {
            String identifier = newGuid();
            Log.d(LINE_SDK_TAG, "'Refresh Access Token' button clicked with identifier={" + identifier + "}");
            lineSdk_refreshAccessToken(identifier);
        });

        binding.btnRevokeAccessToken.setOnClickListener(view -> {
            String identifier = newGuid();
            Log.d(LINE_SDK_TAG, "'Revoke Access Token' button clicked with identifier={" + identifier + "}");
            lineSdk_revokeAccessToken(identifier);
        });

        binding.btnVerifyAccessToken.setOnClickListener(view -> {
            String identifier = newGuid();
            Log.d(LINE_SDK_TAG, "'Verify Access Token' button clicked with identifier={" + identifier + "}");
            lineSdk_verifyAccessToken(identifier);
        });
    }

    /**
     * Set up Inputs Dialog click listener
     */
    @Override
    public void onPositiveButtonClick(DialogInterface dialog, int id, @NonNull String result) {
        try {
            switch (id) {
                case LISTENER_ID_LOGIN:
                    String identifier = newGuid();
                    String scope = ResultModel.getValue(result, KEY_SCOPE);
                    boolean onlyWebLogin = Boolean.parseBoolean(ResultModel.getValue(result, KEY_ONLY_WEB_LOGIN));
                    String botPrompt = ResultModel.getValue(result, KEY_BOT_PROMPT).isEmpty() ?
                            null : ResultModel.getValue(result, KEY_BOT_PROMPT);
                    String tokenNonce = ResultModel.getValue(result, KEY_TOKEN_NONCE).isEmpty() ?
                            null : ResultModel.getValue(result, KEY_TOKEN_NONCE);

                    Log.d(LINE_SDK_TAG, "Login dialog: scope={" + scope + "}, " +
                            "onlyWebLogin={" + onlyWebLogin + "}, " +
                            "botPrompt={" + botPrompt + "}, " +
                            "tokenNonce={" + tokenNonce + "}");

                    lineSdk_login(identifier, scope, onlyWebLogin, botPrompt, tokenNonce);
                    dialog.dismiss();
                    break;
            }
        } catch (Throwable ignore) {
            dialog.dismiss();
        }
    }
}
