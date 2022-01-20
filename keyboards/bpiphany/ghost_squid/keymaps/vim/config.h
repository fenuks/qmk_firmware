#define LEADER_TIMEOUT 300
/* reset timeout after every keypress */
#define LEADER_PER_KEY_TIMING

/* time to wait for double tap or stopping ignoring tap interrupt  */
#define TAPPING_TERM 200

/* Enable rapid switch from tap to hold, disables double tap hold auto-repeat. */
/* #define TAPPING_FORCE_HOLD */

/* timeout for one time shot */
#define ONESHOT_TIMEOUT 5000

/* Prevent normal rollover on alphas from accidentally triggering mods. */
#define IGNORE_MOD_TAP_INTERRUPT

/* Input unicode with Linux D-Bus based protocol */
#define UNICODE_SELECTED_MODES UC_LNX

#define AUTO_SHIFT_TIMEOUT 200

/* If you press a dual-role key, tap another key (press and release) and
then release the dual-role key, all within the tapping term, by default the
dual-role key will perform its tap action. If the PERMISSIVE_HOLD option is
enabled, the dual-role key will perform its hold action instead. */
/* #define PERMISSIVE_HOLD */

#ifdef DEBOUNCE
#    undef DEBOUNCE
#endif
#define DEBOUNCE 8
