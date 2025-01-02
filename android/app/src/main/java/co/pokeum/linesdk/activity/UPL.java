package co.pokeum.linesdk.activity;

import android.content.Intent;
import android.os.Bundle;

import org.jetbrains.annotations.NotNull;
import org.jetbrains.annotations.Nullable;

import co.pokeum.linesdk.unrealwrapper.LineSdkWrapper;

public abstract class UPL extends Game {

//================================================================================================================//

    public void lineSdk_logger(String message) { android.util.Log.d(LINE_SDK_TAG, message); }

    public void lineSdk_setupSdk(@NotNull String channelId) {
        LineSdkWrapper.setupSdk(getApplicationContext(), channelId);
    }

    public void lineSdk_login(
            @NotNull String identifier,
            @NotNull String scope,
            boolean onlyWebLogin,
            @Nullable String botPrompt,
            @Nullable String tokenNonce
    ) {
        LineSdkWrapper.login(this, identifier, scope, onlyWebLogin, botPrompt, tokenNonce);
    }

    public void lineSdk_getProfile(@NotNull String identifier) {
        LineSdkWrapper.getProfile(identifier);
    }

    public String lineSdk_getCurrentAccessToken() {
        return LineSdkWrapper.getCurrentAccessToken();
    }

    public void lineSdk_logout(@NotNull String identifier) {
        LineSdkWrapper.logout(identifier);
    }

    public void lineSdk_getBotFriendshipStatus(@NotNull String identifier) {
        LineSdkWrapper.getBotFriendshipStatus(identifier);
    }

    public void lineSdk_refreshAccessToken(@NotNull String identifier) {
        LineSdkWrapper.refreshAccessToken(identifier);
    }

    public void lineSdk_revokeAccessToken(@NotNull String identifier) {
        LineSdkWrapper.revokeAccessToken(identifier);
    }

    public void lineSdk_verifyAccessToken(@NotNull String identifier) {
        LineSdkWrapper.verifyAccessToken(identifier);
    }

//================================================================================================================//

    @Override
    protected void gameActivityReadMetadata(Bundle bundle) {

// e.g.
//        if (bundle.containsKey("co.pokeum.linesdk.ChannelId"))
//        {
//            Object channelId = bundle.get("co.pokeum.linesdk.ChannelId");
//            if (channelId != null) {
//                LineSdkWrapper.setupSdk(getApplicationContext(), channelId.toString());
//            }
//        }
    }

    @Override
    protected void gameActivityOnCreateAdditions() {

    }

    @Override
    protected void gameActivityOnDestroyAdditions() {

    }

    @Override
    protected void gameActivityOnStartAdditions() {

    }

    @Override
    protected void gameActivityOnStopAdditions() {

    }

    @Override
    protected void gameActivityOnPauseAdditions() {

    }

    @Override
    protected void gameActivityOnResumeAdditions() {

    }

    @Override
    protected void gameActivityOnNewIntentAdditions(Intent newIntent) {

    }

    @Override
    protected void gameActivityOnActivityResultAdditions(int requestCode, int resultCode, Intent data) {

    }
}
