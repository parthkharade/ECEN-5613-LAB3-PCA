/**
 * @brief Initialise the PCA to use Fclk/2 and enable WDT,PWM and Highspeed output mode
 * 
 */
void init_pca();
/**
 * @brief Starts the pwm module of the PCA
 * 
 */
void start_pwm();

/**
 * @brief Stops the pwm module of the PCA
 * 
 */
void stop_pwm();
/**
 * @brief Starts the High speed output module of the PCA
 * 
 */
void start_tog();

/**
 * @brief Stops the high speed output module of the pca
 * 
 */
void stop_tog();

/**
 * @brief Enable the WDT
 * 
 */
void enable_dog();

/**
 * @brief Disable the WDT
 * 
 */
void disable_dog();