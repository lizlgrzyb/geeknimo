<div class="row">
  <form class="col-md-4" role="form" action="{$smarty.server.SCRIPT_NAME}?page=login" method="post" id="loginForm">
    <input type="hidden" name="ctoken" value="{$CTOKEN|escape|default:""}">
    <div class="panel panel-info">
      <div class="panel-heading">
        <i class="fa fa-sign-in fa-fw"></i> �˺ŵ�½
      </div>
      <div class="panel-body">
        <div class="form-group">
          <div class="input-group input-group-sm">
            <span class="input-group-addon"><i class="fa fa-envelope-o fa-fw"></i></span>
            <input class="form-control" placeholder="���������ַ" name="username" type="email" autofocus required>
          </div>
          <div class="input-group input-group-sm">
            <span class="input-group-addon"><i class="fa fa-key fa-fw"></i></span>
            <input class="form-control" placeholder="���ĵ�½����" name="password" type="password" value="" required>
          </div>
        </div>
      </div>
      <center>{nocache}{$RECAPTCHA|default:"" nofilter}{/nocache}</center>
      <div class="panel-footer">
        <input type="submit" class="btn btn-success btn-sm" value="��½" >
        <a href="{$smarty.server.SCRIPT_NAME}?page=password"><font size="1">�������룿</font></a>
      </div>
    </div>
  </form>
</div>