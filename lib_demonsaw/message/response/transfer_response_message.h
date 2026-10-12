// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _EJA_FILE_RESPONSE_MESSAGE_
#define _EJA_FILE_RESPONSE_MESSAGE_

#include <memory>

#include "json/json.h"
#include "json/json_message.h"
#include "json/json_value.h"
#include "json/value/json_server.h"

namespace eja
{
	class transfer_response_message final : public json_message
	{
	public:
		using ptr = std::shared_ptr<transfer_response_message>;

	private:
		transfer_response_message() : json_message(json_type::transfer, json_action::response) { }
		transfer_response_message(const json_message::ptr& message) : json_message(message, json_type::transfer, json_action::response) { }
		transfer_response_message(const json_value::ptr& value) : json_message(value, json_type::transfer, json_action::response) { }

	public:        
		virtual ~transfer_response_message() override { }

		// Utility
		virtual bool valid() const override { return json_message::valid() && has_server(); }
		bool has_server() const { return get_value().isMember(json::server) && !get_value()[json::server].empty(); }

		// Accessor
		json_server::ptr get_server() { return json_server::create(shared_from_this(), json::server); }

		// Static
		static ptr create() { return ptr(new transfer_response_message()); }
		static ptr create(const json_message::ptr& message) { return ptr(new transfer_response_message(message)); }
		static ptr create(const json_value::ptr& value) { return ptr(new transfer_response_message(value)); }
	};
}

#endif
