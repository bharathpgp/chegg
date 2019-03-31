<%@ page language="java" contentType="text/html; charset=ISO-8859-1"

pageEncoding="ISO-8859-1"%>

<%@ page import = "ccPaymentSchedule.CreditCard" %>

<%

   CreditCard cc = new CreditCard(); //Unsure if necessary

%>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<html>

<head>

    <meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">

    <title>Credit Card Payment Schedule</title>

</head>

<body>

    <h1>Credit Card Payment Schedule</h1>

    <p>Enter first and last name</p>

    <form name="nameForm" action="name.jsp" method="get">

        <label>

            Enter your first and last name:

        </label>

        <input type="text" name="names" value="0" />

        <label>

            Enter your account number:

        </label>

        <input type="text" name="accountNum" value="0" />

        <label>

            Enter balance:

        </label>

        <input type="text" name="balance" value="0" />

        <br>

        <input type="submit" name="nameButton" value="Go" />

    </form>

</body>

</html>