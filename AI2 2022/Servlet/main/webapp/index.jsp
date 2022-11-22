<%@ page import="java.util.Random" %>
<%@ page contentType="text/html; charset=UTF-8" %>

<html>
<body>

<%
    String[] jokes = {
            "Jak się czuje ogórek w towarzystwie śmietany?\n" +
                    "Mizernie.",
            "Co to jest? W dzień się nie zamyka, aw nocy pływa w wodzie?\n" +
                    "Szczęka teściowej.",
            "Co to jest? Leży w trawie i nie dycha?\n" +
                    "Dwie dychy",
            "Gdzie podpisano traktat wersalski?\n" +
                    "-Na samym dole,pod tekstem."
    };
    int idx = new Random().nextInt(jokes.length);
    String joke = jokes[idx];
    if (session.getAttribute("firstName") == null) {

%>
<form action="save" method="POST">
    First Name:<input type="text" name="firstName">
    <input type="submit" , value="Save">
</form>
<%
} else {
%>
<h2>Hello <%=session.getAttribute("firstName")%>
</h2>

<h2><%=joke%>
</h2>

<form action="forget" method="GET">
    <input type="submit" , value="Forget">
</form>
<%
    }
%>

</body>
</html>
