/***
 * URL
 */
export  class ApiUrl {
  /**后台服务*/
  public static SERVER:string = 'https://39.106.96.168:8446/api';
  /**获取认证费用定价 */
  public static GET_PRICE:string = ApiUrl.SERVER +'/getPrice';
  public static SEND_CODE:string = ApiUrl.SERVER +'/sendCode';
  /**用户信息认证接口*/
  public static AUTH:string = ApiUrl.SERVER +'/authreqstatus/auth';
  /**APP认证结果请求接口 */
  public static APP_AUTH:string = ApiUrl.SERVER +'/app/auth';
}
