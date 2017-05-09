<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ page import="com.test.pojo2.Fuheplan2" %>
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
    <%--<s:action name="query_all2" namespace="/"></s:action>--%>
    <table class="table table-striped">
        <thead>
        <tr>
            <th>ID</th>
            <th>字段一</th>
            <th>字段二</th>
            <th>字段三</th>
        </tr>
        </thead>
        <tbody>
        <tr>
            <td>
                <%=Fuheplan2.FIELD_PLANID %>
            </td>
            <td>
                <%=Fuheplan2.FIELD_PLANVALUE %>
            </td>
            <td>
                <%=Fuheplan2.FIELD_PLANTIME %>
            </td>
            <td>
                <%=Fuheplan2.FIELD_PLANSORTID %>
            </td>
        </tr>
        <s:iterator value="list2">
            <tr>
                <td>
                    <s:property value="planId2"/>
                </td>
                <td>
                    <s:property value="planValue2"/>
                </td>
                <td>
                    <s:property value="planTime2"/>
                </td>
                <td>
                    <s:property value="planSortId2"/>
                </td>
            </tr>
        </s:iterator>
        </tbody>
    </table>

<!-- Bootstrap core JavaScript
================================================== -->
<!-- Placed at the end of the document so the pages load faster -->
<script src="http://cdn.bootcss.com/jquery/1.11.1/jquery.min.js"></script>
<script src="js/bootstrap.min.js"></script>
<script src="js/docs.min.js"></script>
</body>
</html>