<?xml version="1.0" encoding="UTF-8"?>

<!-- New XSLT document created with EditiX XML Editor (http://www.editix.com) at Tue Mar 07 16:09:41 CET 2023 -->

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:output method="html"/>
	
	<xsl:template match="/"> 
	<html> 
	 <head> 
	 	<title> 
	 		Countries of the world 
	 	</title> 
	 </head> 
	 
	 <body style="background-color:white;"> 
	 	<h1>Information about the countries</h1> 
	 	Styled by: Gabriel Canaple, Mohamed Fayala (B3329)
	 	<xsl:apply-templates></xsl:apply-templates>
	 	<ul>
			<xsl:for-each select = "//country[count(./languages/node())>2]">
			 	<li><xsl:value-of select="./country_name/common_name"/></li>
			 </xsl:for-each>
		</ul>
	 </body> 
	</html> 
	</xsl:template> 
	
	<xsl:template match="metadonnees">
	 <p style="text-align:center; color:green;">
		Objectif : <xsl:value-of select="objectif"/>
	 </p><hr/><hr/>
	</xsl:template>
	
	
	<xsl:template match="country">
	<table border="3" width="100%" align="center">
		
<tr>
		
	<td>
		
	 <span STYLE="text-align:center; font-weight:bold;">N°</span>
		
	</td>
		
	<td>
		
	 <span STYLE="text-align:center; font-weight:bold;">Name</span>
		
	</td>
		
	<td>
		
	 <span STYLE="text-align:center; font-weight:bold;">Capital</span>
		
	</td>
		
	<td>
		
	 <span STYLE="text-align:center; font-weight:bold;">Coordinates</span>
		
	</td>
		
	<td>
		
	 <span STYLE="text-align:center; font-weight:bold;">Neighbours</span>
		
	</td>
		
	<td>
		
	 <span STYLE="text-align:center; font-weight:bold;">Flag</span>
		
	</td>
		
	<td>
		
	 <span STYLE="text-align:center; font-weight:bold;">Spoken Languages</span>
		
	</td>
		
</tr>
		<xsl:for-each select = "//country">
		<tr>
			<td>
				<xsl:value-of select='count(./preceding-sibling::country)+1'/> 
			</td>
			
			<td >
				<span style="color:green;">
				<xsl:value-of select="./country_name/offic_name"/> 
				</span>
				
				( <xsl:value-of select="./country_name/common_name"/> )
				<br/>
				<xsl:if test='./country_name/native_name[@lang="fra"]'>
					<span style="color:blue;">
						Nom français: <xsl:value-of select='./country_name/native_name[@lang="fra"]/offic_name'/> 
					</span>
				</xsl:if>
			</td>
			
			<td>
			
			<xsl:value-of select="./capital"/> 
			
			</td>
			
			<td>
			
			Latitude: <xsl:value-of select="./coordinates/@lat"/> <br/>
			Longitude: <xsl:value-of select="./coordinates/@long"/> 
			
			</td>
			
			<td>
				<xsl:choose>
				  <xsl:when test="count(./borders/neighbour)=0">
				    Île
				  </xsl:when>
				  <xsl:otherwise>
				    <xsl:for-each select="./borders/neighbour[position() != last()]">
				    	<xsl:variable name="nei" select="current()"/>
				    	<xsl:value-of select="//common_name[contains(../../country_codes/cca3,$nei)]"/>, 
				    </xsl:for-each>
				    <xsl:variable name="nei" select="./borders/neighbour[last()]"/>
				    <xsl:value-of select="//common_name[contains(../../country_codes/cca3,$nei)]"/>
				  </xsl:otherwise>
				</xsl:choose>
			</td>
			
			<td>
			
	<img src='http://www.geonames.org/flags/x/{
translate(country_codes/cca2, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "abcdefghijklmnopqrstuvwxyz")}.gif' alt="" height="40" width="60"/> 
			</td>
			
			<td>
				<xsl:for-each select="./languages/descendant::*[position() != last()]">
			    	<xsl:value-of select="text()"/>, 
			    </xsl:for-each>
			    <xsl:value-of select="./languages/descendant::*[last()]/text()"/>
			</td>
		</tr>
		</xsl:for-each>
		
	</table>
		 
	</xsl:template>

</xsl:stylesheet>


