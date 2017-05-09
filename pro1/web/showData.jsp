<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%--<%@ page import="com.test.pojo.Fuheplan2" %>--%>
<%@ taglib prefix="s" uri="/struts-tags" %>
<%--<%@ page import="com.test.pojo.Fuheplan2" %>&lt;%&ndash;--%>
<%--
  Created by IntelliJ IDEA.
  User: 世康
  Date: 2016/9/11
  Time: 19:44
  To change this template use File | Settings | File Templates.
--%>
<!DOCTYPE html>
<html lang="zh_cn">
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="">
    <meta name="author" content="">
    <link rel="icon" href="">

    <title>数据显示</title>

    <!-- Bootstrap core CSS -->
    <link href="css/bootstrap.min.css" rel="stylesheet">

    <!-- Custom styles for this template -->
    <link href="css/dashboard.css" rel="stylesheet">

    <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
    <!--[if lt IE 9]>
    <script src="http://cdn.bootcss.com/html5shiv/3.7.0/html5shiv.js"></script>
    <script src="http://cdn.bootcss.com/respond.js/1.4.2/respond.min.js"></script>
    <![endif]-->
</head>

<body>

<nav class="navbar navbar-inverse navbar-fixed-top" role="navigation">
    <div class="container-fluid">
        <div class="navbar-header">
            <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
                <span class="sr-only">Toggle navigation</span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
            </button>
            <a class="navbar-brand" href="#">数据显示</a>
        </div>
        <div id="navbar" class="navbar-collapse collapse">
            <ul class="nav navbar-nav navbar-right">
                <li><a href="#">回到顶部</a></li>
                <%--<li><a href="#">帮助</a></li>--%>
            </ul>
            <form class="navbar-form navbar-right">
                <input type="text" class="form-control" placeholder="Search...">
            </form>
        </div>
    </div>
</nav>

<div class="container-fluid">
    <div class="row">
        <div class="col-sm-3 col-md-2 sidebar">
            <ul class="nav nav-sidebar">
                <li class="active"><a onclick="change1()">原表数据</a></li>
                <li><a onclick="change2()">数据对比</a></li>
                <%--<li><a href="javascript:void(0);">表三</a></li>--%>
                <%--<li><a href="javascript:void(0);">表四</a></li>--%>
            </ul>
            <%--<ul class="nav nav-sidebar">--%>
            <%--<li><a href="">Nav item</a></li>--%>
            <%--<li><a href="">Nav item again</a></li>--%>
            <%--<li><a href="">One more nav</a></li>--%>
            <%--<li><a href="">Another nav item</a></li>--%>
            <%--<li><a href="">More navigation</a></li>--%>
            <%--</ul>--%>
            <%--<ul class="nav nav-sidebar">--%>
            <%--<li><a href="">Nav item again</a></li>--%>
            <%--<li><a href="">One more nav</a></li>--%>
            <%--<li><a href="">Another nav item</a></li>--%>
            <%--</ul>--%>
        </div>
        <div class="col-sm-9 col-sm-offset-3 col-md-10 col-md-offset-2 main">
            <h1 class="page-header">概览</h1>

            <div class="row placeholders">
                <%--<div class="col-xs-6 col-sm-3 placeholder">--%>
                    <%--<img data-src="holder.js/200x200/auto/sky" class="img-responsive" alt="Generic placeholder thumbnail">--%>
                    <%--<h4>Label</h4>--%>
                    <%--<span class="text-muted">Something else</span>--%>
                <%--</div>--%>
                <%--<div class="col-xs-6 col-sm-3 placeholder">--%>
                    <%--<img data-src="holder.js/200x200/auto/vine" class="img-responsive" alt="Generic placeholder thumbnail">--%>
                    <%--<h4>Label</h4>--%>
                    <%--<span class="text-muted">Something else</span>--%>
                <%--</div>--%>
                <%--<div class="col-xs-6 col-sm-3 placeholder">--%>
                    <%--<img data-src="holder.js/200x200/auto/sky" class="img-responsive" alt="Generic placeholder thumbnail">--%>
                    <%--<h4>Label</h4>--%>
                    <%--<span class="text-muted">Something else</span>--%>
                <%--</div>--%>
                <%--<div class="col-xs-6 col-sm-3 placeholder">--%>
                    <%--<img data-src="holder.js/200x200/auto/vine" class="img-responsive" alt="Generic placeholder thumbnail">--%>
                    <%--<h4>Label</h4>--%>
                    <%--<span class="text-muted">Something else</span>--%>
                <%--</div>--%>
            </div>

            <h2 class="sub-header"><a onclick="myrefresh()">数据刷新</a></h2>
            <%--<input type="button" name="myfresh" value="数据刷新" onclick="myrefresh()"/>--%>
            <div class="table-responsive">
                <iframe src="query_all.action" id="iframepage1" frameborder="0" scrolling="no" align="left" width="50%" marginheight="0" marginwidth="0" onLoad="iFrameHeight1()"></iframe>
                <iframe src="query_all2.action" id="iframepage2" frameborder="0" scrolling="no" align="right" width="50%" marginheight="0" marginwidth="0" onLoad="iFrameHeight2()"></iframe>
            </div>
    </div>
</div>
</div>

<script language="JavaScript">
    function myrefresh()
    {
        window.location.reload();
    }
</script>

<script type="text/javascript" language="JavaScript">
    function change1() {
        document.getElementById("iframepage1").src="query_all.action";
        document.getElementById("iframepage2").src="query_all2.action";
    }
</script>

<script type="text/javascript" language="JavaScript">
    function change2() {
        document.getElementById("iframepage1").src="query_all3.action";
        document.getElementById("iframepage2").src="query_all4.action";
    }
</script>

<script type="text/javascript" language="javascript">
    function iFrameHeight1() {
        var ifm= document.getElementById("iframepage1");
        var subWeb = document.frames ? document.frames["iframepage1"].document : ifm.contentDocument;
        if(ifm != null && subWeb != null) {
            ifm.height = subWeb.body.scrollHeight;
        }
    }
</script>

<script type="text/javascript" language="javascript">
    function iFrameHeight2() {
        var ifm= document.getElementById("iframepage2");
        var subWeb = document.frames ? document.frames["iframepage2"].document : ifm.contentDocument;
        if(ifm != null && subWeb != null) {
            ifm.height = subWeb.body.scrollHeight;
        }
    }
</script>

<!-- Bootstrap core JavaScript
================================================== -->
<!-- Placed at the end of the document so the pages load faster -->
<script src="http://cdn.bootcss.com/jquery/1.11.1/jquery.min.js"></script>
<script src="js/bootstrap.min.js"></script>
<script src="js/docs.min.js"></script>
</body>
</html>

